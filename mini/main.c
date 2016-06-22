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
int mux1,mux2;
char world[MAXLEN];
TokenSet getToken(void)
{
    int i;
    char c;

    while ( (c = fgetc(stdin)) == ' ' || c== '\t' );  // deal with space
    world[w]=c;
    if(c==EOF) {
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
        else return UNKNOWN;
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
int xs;
int ys;
int zs;
int flagl;
int flagi=3;
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

int getval(void)
{

    int  retval;
    retval = 0;
    if(match(X))
    {

        flagx = 1;
        return x=retval ;
    }
    else if(match(Y))
    {


        flagy = 1;
        return y=retval ;
    }
     else if(match(Z))
    {

        flagz = 1;

        return z=retval ;
    }
    else if(match(INT))
    {
        retval = atoi(lexeme);
        if(!flagx &&!flagy &&!flagz&&!flagl){
            error();
        }
    }
    else if(match(LPAREN))
    {
        advance();
        retval = expr();
        return retval ;
    }
    else if(match(RPAREN)){

    }
    else if(match(UNKNOWN)) {
            error();
        }
return retval ;
}

int expr(void)
{
    int retval;
    retval = term();
    while (match(ADDSUB))
    {
        if (strcmp(lexeme, "+")==0)
        {
            advance();
            retval += term();
            if(flagi > 3)
            {
                if(!match(ADDSUB)&&!match(X)&&!match(Y)&&!match(Z)&&!match(INT)&&!match(END)) {
                        error();
                }

                if(xs ==1)
                {
                    printf("ADD r0, r%d\n",flagi-1);
                    if(ys==1||zs==1) xs--;
                }
                else if(ys ==1)
                {
                    printf("ADD r1, r%d\n",flagi-1);
                     if(xs==1||zs==1) ys--;
                }

                else if(zs ==1)
                {
                    printf("ADD r2, r%d\n",flagi-1);
                     if(ys==1||xs==1) ys--;
                }

            }

        }
        else if (strcmp(lexeme, "-")==0)
        {
            advance();
            retval -= term();
            if(flagi >3){
                    if(!match(ADDSUB)&&!match(X)&&!match(Y)&&!match(Z)&&!match(INT)&&!match(END)) {

                        error();
                }

                if(xs)
                printf("SUB r0, r%d\n",flagi-1);
            else if(ys)
                printf("SUB r1, r%d\n",flagi-1);
            else if(zs)
                printf("SUB r2, r%d\n",flagi-1);
            }

        }
        else
        {
        }
    }


    return retval;
}

int term(void)
{
    int retval;
    int a,b;
    retval = factor();
    int zz,zzz;
        zz = w;
        while (match(MULDIV))
        {
            if (strcmp(lexeme, "*")==0)
            {
                a = flagi;

                printf("zz:%d\n",zz);
                advance();

                if(!match(END)&&!match(INT)&&!match(X)&&!match(Y)&&!match(Z)&&!match(ADDSUB)) {
                        error();
                }
                retval *= factor();
                b = flagi;
                zzz=w;
                printf("ZZZ:%d\n",zzz);
                if(isalpha(world[zz]) && isalpha(world[zzz])){
                         if(world[zz]=='x'&&world[zzz]=='x'){
                        printf("MUL r0, r0\n");
                    }
                    else if(world[zz]=='x'&&world[zzz]=='y'){
                        printf("MUL r0, r1\n");
                    }
                    else if(world[zz]=='x'&&world[zzz]=='z'){
                        printf("MUL r0, r2\n");
                    }
                    else if(world[zz]=='y'&&world[zzz]=='y'){
                        printf("MUL r1, r1\n");
                    }
                    else if(world[zz]=='y'&&world[zzz]=='z'){
                        printf("MUL r1, r2\n");
                    }
                    else if(world[zz]=='y'&&world[zzz]=='x'){
                        printf("MUL r1, r0\n");
                    }
                    else if(world[zz]=='z'&&world[zzz]=='z'){
                        printf("MUL r2, r2\n");
                    }
                    else if(world[zz]=='z'&&world[zzz]=='y'){
                        printf("MUL r2, r1\n");
                    }
                    else if(world[zz]=='z'&&world[zzz]=='x'){
                        printf("MUL r2, r0\n");
                    }
                }
                else if(b>4){
                    printf("MUL r%d, r%d\n",a-1,b-1);
                }
                else if(xs&&b==4)
                    printf("MUL r0, r%d\n",flagi-1);
                else if(ys&&b==4)
                    printf("MUL r1, r%d\n",flagi-1);
                else if(zs&&b==4)
                    printf("MUL r2, r%d\n",flagi-1);
            }
            else if (strcmp(lexeme, "/")==0)
            {
                a= flagi;
                zz= w;
                advance();

                int di;
                di = factor();
                b=flagi;
                if(di==0) error();
                zzz=w;
                retval /= di;
                if(isalpha(world[zz]) && isalpha(world[zzz])){
                         if(world[zz]=='x'&&world[zzz]=='x'){
                        printf("DIV r0, r0\n");
                    }
                    else if(world[zz]=='x'&&world[zzz]=='y'){
                        printf("DIV r0, r1\n");
                    }
                    else if(world[zz]=='x'&&world[zzz]=='z'){
                        printf("DIV r0, r2\n");
                    }
                    else if(world[zz]=='y'&&world[zzz]=='y'){
                        printf("DIV r1, r1\n");
                    }
                    else if(world[zz]=='y'&&world[zzz]=='z'){
                        printf("DIV r1, r2\n");
                    }
                    else if(world[zz]=='y'&&world[zzz]=='x'){
                        printf("DIV r1, r0\n");
                    }
                    else if(world[zz]=='z'&&world[zzz]=='z'){
                        printf("DIV r2, r2\n");
                    }
                    else if(world[zz]=='z'&&world[zzz]=='y'){
                        printf("DIV r2, r1\n");
                    }
                    else if(world[zz]=='z'&&world[zzz]=='x'){
                        printf("DIV r2, r0\n");
                    }
                }
                else if(!match(END)&&!match(INT)&&!match(X)&&!match(Y)&&!match(Z)&&!match(ADDSUB)) {
                        error();
                }
                if(b>4){
                    printf("DIV r%d, r%d\n",a-1,b-1);
                }
                else if(xs&&b==4)
                    printf("DIV r0, r%d\n",flagi-1);
                else if(ys&&b==4)
                    printf("DIV r1, r%d\n",flagi-1);
                else if(zs&&b==4)
                    printf("DIV r2, r%d\n",flagi-1);
            }
            else
            {


            }
        }



    return retval;
}

int factor(void)
{
    int retval = 0;


    if (match(X)||match(Y)||match(Z))
    {
        retval = getval();
    }
    else if(match(INT))
    {
        retval = getval();
        printf("MOV r%d, %d\n",flagi,retval);
        flagi++;
        if(xs>2) xs=1;
        else if(ys>2) ys = 1;
        else if(zs >2) zs = 1;
        advance();
    }
    else if(match(MULDIV)){
        if(strcmp(lexeme,"*")){

        }

        else{
        }
    }
    return retval ;
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
        printf("EXIT 0\n");

        printf("r[0] = %d\n",x);
        printf("r[1] = %d\n",y);
        printf("r[2] = %d\n",z);

        xs=0;
        ys=0;
        zs=0;
        flagx=0;
        flagy=0;
        flagz=0;
        flagi=3;
        advance();
    }
    else
    {
        retval = expr();
        if(xs>0)x = retval ;
        else if(ys > 0) y = retval ;
        else if(zs > 0) z = retval ;
        if (match(END))
        {
            xs=0;
            ys=0;
            zs=0;
            w=0;
            flagi=3;
            advance();
        }
    }
}

int main()
{
    while (1)
    {
        statement();
    }
    return 0;
}
