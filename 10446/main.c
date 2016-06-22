#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("MOV r0, 10\n");
    printf("MOV r1, 20\n");
    printf("MOV r2, 30\n");
    printf("MOV r3, 40\n");
    printf("JMP L2\n");
    printf("L3 :\n");
    printf("CMP r1, r2\n");

    printf("JLE L4\n");

    printf("CMP r0, r1\n");
    printf("JLE L5\n");
    printf("ADD r0, 2\n");
    printf("JMP L2\n");
    printf("L5 :\n");

    printf("ADD r0, 1\n");

    printf("JMP L2\n");
    printf("L4 :\n");
    printf("ADD r0, 1\n");
    printf("ADD r1, 1\n");
    printf("L2 :\n");

    printf("CMP r0, r3\n");
    printf("JLE L3\n");


    return 0;
}
