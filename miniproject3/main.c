#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#ifndef __LEX__
#define __LEX__
#define MAXLEN 100
typedef enum {UNKNOWN, END, INT,ID, ADDSUB, MULDIV, ASSIGN,
              LPAREN, RPAREN
             } TokenSet;
char lexeme[MAXLEN];

extern int match (TokenSet token);
extern void advance(void);
#endif // __LEX__

static TokenSet getToken(void);
static TokenSet lookahead = UNKNOWN;
int w;
int mux1,mux2;
char world[MAXLEN];
TokenSet getToken(void)
{
    int i;
    char c;

    while ( (c = fgetc(stdin)) == ' ' || c== '\t' );  // deal with space
    world[w]=c;
    if(c==EOF)
    {
        w++;
        return END;
    }
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

    else if (c == 'x' || c == 'y' || c == 'z')
    {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return ID;

    }
    else
    {
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


int x;
int y;
int z;

int flagl;
int flagi ;
void statement(void);
int expr(void);
int term(void);
int factor(void);
int getval(void);
int setval(char*, int);
void error(void);
int flagx;
int flagy;
int flagz;
int flag;
int getval(void)
{
    int retval ;

    if (match(INT))
    {
        retval = atoi(lexeme);
    }
    else if (match(ID))
    {
        retval = lexeme[0] - 'x';
    }
    return retval;
}
int expr(void)
{
    int retval;

    retval = term();

    if     (flagl)
        printf("MOV r%d, r3\n", flagi);
    else if(flag)
        printf("MOV r%d, r%d\n", flagi, retval);
    else
        printf("MOV r%d, %d\n", flagi, retval);

    flag = 0;
    while (match(ADDSUB))
    {
        if(strcmp(lexeme,"+") == 0)
        {
            advance();
            retval = term();
            if(flagl)
            {
                 printf("ADD r%d, r3\n", flagi);
            }

            else if(flag)
            {
                printf("ADD r%d, r%d\n", flagi, retval);
            }

            else
            {
                printf("ADD r%d, %d\n", flagi, retval);
            }


        }
        else if(strcmp(lexeme,"-") == 0)
        {
            advance();
            retval = term();
            if(flagl)
            {
                 printf("SUB r%d, r3\n", flagi);
            }

            else if(flag)
            {
                printf("SUB r%d, r%d\n", flagi, retval);
            }

            else
            {
                printf("SUB r%d, %d\n", flagi, retval);
            }
        }
        flag = 0;
    }



return retval ;
}
int term(void)
{

    int retval;
    retval = factor();
    flagl = 0;
     if(match(MULDIV))
    {
        if(flag)
            printf("MOV r3, r%d\n", retval);
        else
            printf("MOV r3, %d\n", retval);
        flagl = 1;
    }
    flag = 0;
    while (match(MULDIV))
    {
        if (strcmp(lexeme, "*") == 0)
        {
            advance();
            retval = factor();
            if(flag)
                printf("MUL r3, r%d\n", retval);
            else
                printf("MUL r3, %d\n", retval);

        }
        else if(strcmp(lexeme,"/") == 0)
        {
            advance();
            retval = factor();
            if(flag)
                printf("DIV r3, r%d\n", retval);
            else
                printf("DIV r3, %d\n", retval);
        }
            flag = 0;
    }
    return retval ;
}
    int factor(void)
    {
        int retval;
        int id;
        char tmpstr[MAXLEN];
        if (match(INT))
        {
            retval = getval();
            advance();
        }
        else if(match(ID))
        {
            id = getval();

            advance();
            if(match(ASSIGN))
            {
                flagi = id;

                advance();
                flag = 0;
                expr();

            }

        }
        else if (match(ADDSUB))
        {
            strcpy(tmpstr, lexeme);
            advance();
            if (match(ID) || match(INT)) {
                retval = getval();
            if (strcmp(tmpstr, "-")==0) {
                retval = -retval;
            }
            advance();
            }
            else
            {
            error();
            }
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


            printf("r[0] = %d\n",x);
            printf("r[1] = %d\n",y);
            printf("r[2] = %d\n",z);

            advance();
        }
        else
        {
            retval = expr();

            if (match(END))
            {
                printf("EXIT 0\n");
                advance();
            }
        }
    }

    int main(void)
    {
        while (1)
        {
            statement();
        }
        return 0;
    }
