#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("MOV [sp], 5\n");
    printf("MOV [sp+4], 10\n");
    printf("MOV [sp+8], 1\n");
    printf("MOV [sp+12], 2\n");
    printf("MOV r0, 0\n");
    printf("JMP L2\n");
    printf("L3 :\n");
    printf("MOV r1, 0\n");
    printf("JMP L4\n");
    printf("L5 :\n");

    printf("ADD [sp+8], 1\n");



    printf("ADD r1, 1\n");
    printf("L4 :\n");
    printf("CMP r1, [sp+4]\n");


    printf("JLE L5\n");
    printf("ADD [sp+12], 1\n");


    printf("ADD r0, 1\n");
    printf("L2 :\n");


    printf("CMP r0, [sp]\n");

    printf("JLE L3\n");
    printf("MOV r0, [sp]\n");
    printf("MOV r1, [sp+4]\n");
    printf("MOV r2, [sp+8]\n");
    printf("MOV r3, [sp+12]\n");
    return 0;
}
