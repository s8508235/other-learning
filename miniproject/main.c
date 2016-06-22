#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#ifndef __LEX__
#define __LEX__
#define MAXLEN 100
typedef enum {UNKNOWN, END, INT, X,Y,Z, ADDSUB, MULDIV, ASSIGN,
              LPAREN, RPAREN
             } TokenSet;
char lexeme[MAXLEN];

extern int match (TokenSet token);
extern void advance(void);
#endif // __LEX__

static TokenSet getToken(void);
static TokenSet lookahead = UNKNOWN;
int w;
int x;
int y;
int z;
void error(void);
char world[MAXLEN];
TokenSet getToken(void)
{
    int i;
    char c;

    while ( (c = fgetc(stdin)) == ' ' || c== '\t' );  // deal with space

    if (isdigit(c))
    {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isdigit(c) && i<MAXLEN)
        {
            lexeme[i] = c;
            ++i;
            c = fgetc(stdin);
        }
        ungetc(c, stdin);
        w = i;
        lexeme[i] = '\0';
        return INT;
    }
    else if (c == '+' || c == '-')
    {
        lexeme[0] = c;
        lexeme[1] = '\0';
        w++;
        return ADDSUB;
    }
    else if (c == '*' || c == '/')
    {
        lexeme[0] = c;
        lexeme[1] = '\0';
        w++;
        return MULDIV;
    }
    else if (c == '\n')
    {
        lexeme[0] = '\0';
        return END;
    }
    else if (c == '=')
    {
        strcpy(lexeme, "=");
        return ASSIGN;
    }
    else if (c == '(')
    {
        strcpy(lexeme, "(");
        return LPAREN;
    }
    else if (c == ')')
    {
        strcpy(lexeme, ")");
        return RPAREN;
    }
    else if (c == EOF)
    {
        /*
            printf("r[0] = %d\n",x);
            printf("r[1] = %d\n",y);
            printf("r[2] = %d\n",z);
            printf("EXIT 0\n");*/
        exit(0);
    }
    else if (isalpha(c))
    {
        lexeme[0] = c;
        w++;
        if(c=='x')
        {
            lexeme[1] = '\0';
            return X;
        }
        else if(c=='y')
        {
            lexeme[1] = '\0';
            return Y;
        }
        else if(c =='z')
        {
            lexeme[1] = '\0';
            return Z;
        }
        else error();
    }
    else
    {
        return UNKNOWN;
    }
    return UNKNOWN;
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


int flagn;

void statement(void);
void expr(void);
int term(void);
int factor(void);
int getval(void);
int setval(char*, int);
int flag;
int flagx;
int flagy;
int flagz;
int paren;
int flagp;
int getval(void)
{

    int retval;

    if (match(INT))
    {
        retval = atoi(lexeme);
    }
    else if (match(X))
    {
        retval = 0;
    }
    else if(match(Y))
    {
        retval = 1;
    }
    else if(match(Z))
    {
        retval = 2;
    }
    return retval;
}

void expr(void)
{
    int retval;
    flagx=0;
    flagy =0;
    flagz = 0;
    retval = term();
    printf("MOV r%d, r3\n", flagn);
    while (match(ADDSUB))
    {
        flagn = 0;
        if (strcmp(lexeme, "+")==0)
        {
            advance();
            retval = term();
            paren = retval;
            printf("ADD r%d, r3\n", flagn);
        }
        else if (strcmp(lexeme, "-")==0)
        {
            advance();
            retval = term();
            paren = retval ;
            printf("SUB r%d, r3\n", flagn);
        }
    }
}

int term(void)
{
    int retval;
    retval = factor();
    int id = retval;
    flagx=0;
    flagy =0;
    flagz = 0;
    if(!flagn)
    {
        if(flag)
        {
            if(flagn == id)
            {
                printf("MOV r3, [4]\n");
            }
        else
                printf("MOV r3, r%d\n", id);
        }


        else{

        printf("MOV r3, %d\n", id);

        }
    }
    while (match(MULDIV))
    {
        flag = 0 ;
        if (strcmp(lexeme, "*")==0)
        {
            advance();
            retval = factor();
            if(flag)
            {
                if(flagn ==retval)
                {
                    printf("MUL r3, [4]\n");
                }
                else
                    printf("MUL r3, r%d\n", retval);
            }
            else
            {
                if(flagn != id)
                {
                    if(x)
                    {
                        printf("MOV [0], r1\n");
                        printf("MOV r1, %d\n",retval);
                        printf("MUL r3, r1\n");
                        printf("MOV r1, [0]\n");
                    }
                    else if(y)
                    {
                        printf("MOV [0], r2\n");
                        printf("MOV r2, %d\n",retval);
                        printf("MUL r3, r2\n");
                        printf("MOV r2, [0]\n");
                    }
                    else if(z)
                    {
                        printf("MOV [0], r0\n");
                        printf("MOV r0, %d\n",retval);
                        printf("MUL r3, r0\n");
                        printf("MOV r0, [0]\n");
                    }
                }
            }
        }

        else if(strcmp(lexeme, "/")==0)
        {
            advance();
            int p;
            p=factor();
            if(p==0) error();
            retval = p;
            int id = retval;
            if(flag)
            {
                if(flagn ==id)
                {
                    printf("DIV r3, [4]\n");
                }
                else
                    printf("DIV r3, r%d\n", id);
            }
            else
            {
                if(flagn != id)
                {
                    if(x)
                    {
                        printf("MOV [0], r1\n");
                        printf("MOV r1, %d\n",retval);
                        printf("DIV r3, r1\n");
                        printf("MOV r1, [0]\n");
                    }
                    else if(y)
                    {
                        printf("MOV [0], r2\n");
                        printf("MOV r2, %d\n",retval);
                        printf("DIV r3, r2\n");
                        printf("MOV r2, [0]\n");
                    }
                    else if(z)
                    {
                        printf("MOV [0], r0\n");
                        printf("MOV r0, %d\n",retval);
                        printf("MUL r3, r0\n");
                        printf("MOV r0, [0]\n");
                    }
                }
            }

        }
    }
    return retval;
}
int factor(void)
{
            int retval = 0;
            char fat[MAXLEN];
            if (match(INT))
            {
                retval = getval();
                advance();
            }
            else if (match(X))
            {
                flagx++;
                retval = getval();
                flag = 1;
                advance();
                if(flagx>1||flagy>1||flagz>1) error();
                if (match(ASSIGN))
                {
                    flagx=0;
                    x=1;
                    advance();
                    flagn = retval;
                    printf("MOV [4], r0\n");
                    flag = 0;
                    expr();
                }
            }
            else if (match(Y))
            {
                flagy++;
                retval = getval();
                flag = 1;
                advance();
                if(flagx>1||flagy>1||flagz>1) error();
                if (match(ASSIGN))
                {
                    flagy = 0;
                    y=1;
                    advance();
                    flagn = retval;
                    printf("MOV [4], r1\n");
                    flag = 0;
                    expr();
                }
            }
            else if (match(Z))
            {
                flagz++;
                retval = getval();
                flag = 1;
                advance();
                if(flagx>1||flagy>1||flagz>1) error();
                if (match(ASSIGN))
                {
                    flagz = 0;
                    z=1;
                    advance();
                    flagn = retval;
                    printf("MOV [4], r2\n");
                    flag = 0;
                    expr();
                }
            }
              else if (match(ADDSUB))
            {

                strcpy(fat, lexeme);
                advance();
                if (match(X)||match(Y)||match(Z) || match(INT))
                {
                    retval = getval();
                    if (strcmp(fat, "-")==0)
                    {
                        retval = -retval;
                    }
                    advance();
                }
                else if(lexeme[0]=='-')
                {
                    if (match(X)||match(Y)||match(Z) || match(INT))
                    {
                    retval = getval();
                    if (strcmp(fat, "-")==0)
                    {
                        retval = -retval;
                    }
                    advance();
                    }
                }
                else
                {
                    error();
                }
            }
            else if (match(LPAREN))
            {
                advance();
                expr();
                flagp = 1;
                if (match(RPAREN))
                {
                    advance();
                    if(match(MULDIV))
                    {
                    expr();
                }
                else
                {
                    error();
                }
            }
            }
            else
            {
                error();
            }
            return retval;
        }

        void error(void)
        {
            printf("EXIT 1\n");
            exit(0);
        }
        void statement(void)
        {
            int retval;

            if (match(END))
            {
                advance();
            }
            else
            {
                retval = factor();
                if (match(END))
                {
                    advance();
                }
            }
        }

        int main()
        {
            printf("MOV r0, 0\n");
            printf("MOV r1, 0\n");
            printf("MOV r2, 0\n");
            while (1)
            {
                statement();
            }
            return 0;
        }
