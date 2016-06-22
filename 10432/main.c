#include <stdio.h>

#include <stdlib.h>

#include <string.h>

enum code {MOV, ADD};
int r[10];
enum op_type {REG, CONST};

typedef struct INST
{

    enum code opcode;

    enum op_type op1;

    int operand1_value;

    enum op_type op2;

    int operand2_value;

    struct INST* next;

} INST;

/* read input from stdin. */

INST* readInput()
{

    char opc[10], op1[10], op2[10];

    int ns=0, c;

    INST *head=0, *curr=0;

    ns = scanf("%s %s %d ", opc, op1, &c);



    while(ns > 0)
    {

        /* allocate a storage for an instruction */

        if (head == 0)
        {

            head = (INST*) malloc(sizeof(INST));

            curr = head;

            curr->next = 0;

        }
        else
        {

            curr->next = (INST*) malloc(sizeof(INST));

            curr = curr->next;

            curr->next = 0;

        }

        /* set the content of the instruction.*/

        /* opcode */

        if (strcmp(opc, "MOV")==0)

            curr->opcode = MOV;

        else if (strcmp(opc, "ADD")==0)

            curr->opcode = ADD;

        /* Since op1 is always a register, read its id.*/

        curr->op1 = REG;

        curr->operand1_value = op1[1]-'0';

        /* read operand 2.*/

        if (ns == 2)   /* operand 2 is a register*/
        {

            scanf("%s ", op2);

            curr->op2 = REG;

            curr->operand2_value = op2[1] -'0';

        }
        else if (ns == 3)     /* operand 2 is a constant.*/
        {

            curr->op2 = CONST;

            curr->operand2_value = c;

        }

        /* get next one*/

        ns = scanf("%s %s %d ", opc, op1, &c);



    }

    return head;

}
int main ()
{
        INST* m;
        m=readInput();

        while (1)
        {
            if(m->op2 ==REG)
            {
                if(m->opcode ==MOV)
                {
                    r[m->operand1_value]=r[m->operand2_value];
                }
                else
                {
                    r[m->operand1_value]+=r[m->operand2_value];
                }

            }
            else
            {
                if(m->opcode ==MOV)
                {
                    r[m->operand1_value]=m->operand2_value;
                }
                else
                {
                    r[m->operand1_value]+=m->operand2_value;
                }
            }


            if(m->next==0)break;
            m=m->next;
        }
        int i;
        for(i=0;i<4;i++)
        printf("%4d",r[i]);
        printf("\n");

        return 0;
}
