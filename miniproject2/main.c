#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef __LEX__
#define __LEX__
#define MAXLEN 256
typedef enum {UNKNOWN, END, INT, ID, ADDSUB, MULDIV, ASSIGN,
LPAREN, RPAREN} TokenSet;
char lexeme[MAXLEN];

extern int match (TokenSet token);
extern void advance(void);
#endif // __LEX__

static TokenSet getToken(void);
static TokenSet lookahead = UNKNOWN;

TokenSet getToken(void)
{
    int i;
    char c;

    while ( (c = fgetc(stdin)) == ' ' || c== '\t' );  // deal with space

    if (isdigit(c)) {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isdigit(c) && i<MAXLEN) {
            lexeme[i] = c;
            ++i;
            c = fgetc(stdin);
        }
        ungetc(c, stdin);
        lexeme[i] = '\0';
        return INT;
    } else if (c == '+' || c == '-') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return ADDSUB;
    } else if (c == '*' || c == '/') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return MULDIV;
    } else if (c == '\n') {
        lexeme[0] = '\0';
        return END;
    } else if (c == '=') {
        strcpy(lexeme, "=");
        return ASSIGN;
    } else if (c == '(') {
        strcpy(lexeme, "(");
        return LPAREN;
    } else if (c == ')') {
        strcpy(lexeme, ")");
        return RPAREN;
    } else if (c == 'x' || c == 'y' || c == 'z') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return ID;
    } else if (c == EOF) {
        printf("EXIT 0\n");
        exit(0);
    } else {
        return UNKNOWN;
    }
}

void advance(void)
{
    lookahead = getToken();
}

int match(TokenSet token)
{
    if (lookahead == UNKNOWN) advance();
    return token == lookahead;
}



#define TBLSIZE 65535
typedef struct {
    char name[MAXLEN];
    int val;
} Symbol;
Symbol table[TBLSIZE];


void statement(void);
void expr(void);
int term(void);
int factor(void);
int getval(void);

int mainr;
int calr;
int onlyr3;
int Exit;

typedef enum {MISPAREN, NOTNUMID, NOTFOUND, RUNOUT} ErrorType;
void error(ErrorType errorNum);


int getval(void)
{
    int retval;

    if (match(INT)) {
        retval = atoi(lexeme);
    } else if (match(ID)) {
        retval = lexeme[0] - 'x';
    }
    return retval;
}

void expr(void)
{
    int retval;

    retval = term();

    /*if(!calr)
        printf("MOV r%d, %d\n", mainr, retval);
    else if(calr)*/
        printf("MOV r%d, r3\n", mainr);
    while (match(ADDSUB)) {
        calr = 0;
        if (strcmp(lexeme, "+")==0) {
            advance();
            retval = term();
            /*if(!calr){
                printf("ADD r%d, r3\n", mainr);
            } else if(calr){
                if(mainr != retval)
                    printf("ADD r%d, r%d\n", mainr, retval);
                else{
                    printf("MOV r3, [4]\n");
                    printf("ADD r%d, r3\n", mainr);
                }
            }*/
            printf("ADD r%d, r3\n", mainr);
        } else if (strcmp(lexeme, "-")==0) {
            advance();
            retval = term();
            /*if(!calr){
                printf("SUB r%d, r3\n", mainr);
            } else if(calr){
                if(mainr != retval)
                    printf("SUB r%d, r%d\n", mainr, retval);
                else{
                    printf("MOV r3, [4]\n");
                    printf("SUB r%d, r3\n", mainr);
                }
            }*/
            printf("SUB r%d, r3\n", mainr);
        }
    }

}

int term(void)
{
    int retval;
    retval = factor();
    if(calr){
        if(mainr == retval){
            printf("MOV r3, [4]\n");
        }
        else
            printf("MOV r3, r%d\n", retval);
    }else
        printf("MOV r3, %d\n", retval);
    while (match(MULDIV)) {
        calr = 0;
        if (strcmp(lexeme, "*")==0) {
            advance();
            retval = factor();
            if(calr){
                if(mainr == retval){
                    printf("MUL r3, [4]\n");
                }
                else
                    printf("MUL r3, r%d\n", retval);
            } else {

                {
                    printf("MOV [0], r%d\n", (mainr==0)?1:0);
                    printf("MOV r%d, %d\n", (mainr==0)?1:0, retval);
                    printf("MUL r3, r%d\n", (mainr==0)?1:0);
                    printf("MOV r%d, [0]\n", (mainr==0)?1:0);
                }
                calr = 1;
            }
        } else if (strcmp(lexeme, "/")==0) {
            advance();
            retval = factor();
            if(calr){
                if(mainr == retval){
                    printf("DIV r3, [4]\n");
                }
                else
                    printf("DIV r3, r%d\n", retval);
            } else {
                if(mainr != retval){
                        printf("MD\n");
                    printf("MOV [0], r%d\n", (mainr==0)?1:0);
                    printf("MOV r%d, %d\n", (mainr==0)?1:0, retval);
                    printf("DIV r3, r%d\n", (mainr==0)?1:0);
                    printf("MOV r%d, [0]\n", (mainr==0)?1:0);
                }
                calr = 1;
            }
        }
    }
    return retval;
}

int factor(void)
{
    int retval = 0;
    char tmpstr[MAXLEN];

    if (match(INT)) {
        retval = getval();
        advance();
    } else if (match(ID)) {
        retval = getval();
        calr = 1;
        advance();
        if (match(ASSIGN)) {
            advance();
            mainr = retval;
            printf("MOV [4], r%d\n", mainr);
            calr = 0;
            expr();
        }
    } else if (match(ADDSUB)) {
        strcpy(tmpstr, lexeme);
        advance();
        if (match(ID) || match(INT)) {
            retval = getval();
            if (strcmp(tmpstr, "-")==0) {
                retval = -retval;
            }
            advance();
        } else {
            error(NOTNUMID);
        }
    }else if (match(LPAREN)) {
        advance();
        expr();
        if (match(RPAREN)) {
            advance();
        } else {
            error(MISPAREN);
        }
    } else {
        error(NOTNUMID);
    }
    return retval;
}

void error(ErrorType errorNum)
{
    printf("EXIT 1\n");
    exit(0);
}

void statement(void)
{
    int retval;

    if (match(END)) {
        advance();
    } else {
        int a;
        a = factor();
        if (match(END)) {
            advance();
        }
    }

}

int main()
{
    //FILE *fp;
    //fp = freopen("file.txt", "w+", stdout);
    printf("MOV r0, 0\n");
    printf("MOV r1, 0\n");
    printf("MOV r2, 0\n");
    while (1) {
        statement();
    }
    //fclose(fp);
    return 0;
}
