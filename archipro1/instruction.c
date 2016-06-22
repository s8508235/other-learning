#include "stdio.h"
#include "instruction.h"
int mask_31 = 0x80000000;
int  j_mask =  0xf0000000;
int mask_15 = 0x8000;
int mask_4F = 0xffff0000;
int mask_0 = 0x00000000;
int masks[32];
int unmod_pc;
int err_handle = 0;
int instruction_operation(int *opcode,unsigned *reg,int c, int *pc,unsigned *Dmem,unsigned conpc,FILE* err)
{
    err_handle = 0;
    unmod_pc = conpc;
    cycle = c;
    int i;
    for(i=0;i<32;i++)
    {
        masks[i] = 1<<i;// 1 2 4 8 16 ...
    }
    int op_num = 0;
    for(i=0;i<6;i++)
    {
        op_num  = op_num<< 1 ;
        op_num += opcode[i];
    }
    if(op_num == 0)
    {
        instruction_R(opcode,reg,pc,err);
        return R;
    }
    else if(op_num==2 || op_num==3)
    {
        instruction_J(opcode,op_num,reg,pc);
        return J;
    }
    else if(op_num ==63)
    {
        fclose(err);
        return T;
    }
    instruction_I(opcode,op_num,reg,pc,Dmem,err);
    if(err_handle)
    {
        fclose(err);
        return T;
    }
    return I;

}
void instruction_R(int *code,unsigned *reg, int *pc,FILE* err)
{
    unsigned rs,rt,rd,sRs,sRt,sRd,sft;
    int i;
    int func = 0;
    for(i=26;i<32;i++)
    {
        func  = func<< 1 ;
        func += code[i];
    }
    if(func == add)
    {
        int flag =0;
        getrsrtrd(&rs,&rt,&rd,code);
        sRs = (reg[rs] & mask_31)? 1:0;
        sRt = (reg[rt] & mask_31)?1:0;
        reg[rd] = reg[rs] + reg[rt];
        if(rd==0)
        {
            flag = 1;
            err_processing(Writeto0,err);
        }
        sRd = (reg[rd] & mask_31)?1:0;
        if(sRs ==sRt && sRs !=sRd)
        {
            err_processing(NumOver,err);
        }
        if(flag) reg[rd] = 0;
    }
    else if (func == addu)
    {
        getrsrtrd(&rs,&rt,&rd,code);
        reg[rd] = reg[rs] + reg[rt];
        if(rd ==0)
        {
            err_processing(Writeto0,err);
            reg[rd] = 0;
        }
    }
    else if (func == sub)
    {
        int flag = 0;
        getrsrtrd(&rs,&rt,&rd,code);
        sRs = (reg[rs] & mask_31)?1:0;
        sRt = (-(reg[rt]) & mask_31)?1:0;
        reg[rd] = reg[rs] - reg[rt];
        if(rd==0)
        {
            flag = 1;
            err_processing(Writeto0,err);
        }
        sRd = (reg[rd] & mask_31)?1:0;
        if(sRs ==sRt && sRs !=sRd)
        {
            err_processing(NumOver,err);
        }
        if(flag) reg[rd] = 0;
    }
    else if (func == AND)
    {
        getrsrtrd(&rs,&rt,&rd,code);
        reg[rd] = reg[rs] & reg[rt];
        if(rd ==0)
        {
            err_processing(Writeto0,err);
            reg[rd] = 0;
        }
    }
    else if (func == OR)
    {
        getrsrtrd(&rs,&rt,&rd,code);
        reg[rd] = reg[rs] | reg[rt];
        if(rd ==0)
        {
            err_processing(Writeto0,err);
            reg[rd] = 0;
        }
    }
    else if (func == XOR)
    {
        getrsrtrd(&rs,&rt,&rd,code);
        reg[rd] = reg[rs] ^ reg[rt];
        if(rd ==0)
        {
            err_processing(Writeto0,err);
            reg[rd] = 0;
        }
    }
    else if (func == NOR)
    {
        getrsrtrd(&rs,&rt,&rd,code);
        reg[rd] = ~(reg[rs] | reg[rt]);
        if(rd ==0)
        {
            err_processing(Writeto0,err);
            reg[rd] = 0;
        }
    }
    else if (func == NAND)
    {
        getrsrtrd(&rs,&rt,&rd,code);
        reg[rd] = ~(reg[rs] & reg[rt]);
        if(rd ==0)
        {
            err_processing(Writeto0,err);
            reg[rd] = 0;
        }
    }
    else if (func == slt)
    {
        getrsrtrd(&rs,&rt,&rd,code);
        sRs = (reg[rs] & mask_31)?1:0;
        sRt = (reg[rt] & mask_31)?1:0;
        if(sRs < sRt)
            reg[rd] = 0;
        else if(sRs == sRt)
        {
            reg[rd] = (reg[rs] < reg[rt]);
        }
        else
            reg[rd] = 1;
        if(rd ==0)
        {
            err_processing(Writeto0,err);
            reg[rd] = 0;
        }
    }
    else if (func == sll)
    {
        rt = 0;
        for(i=11;i<16;i++)
        {
            rt = rt<<1;
            rt+=code[i];
        }
        rd = 0;
        for(i=16;i<21;i++)
        {
            rd = rd<<1;
            rd +=code[i];
        }
        sft = 0;
        for(i=21;i<26;i++)
        {
            sft = sft <<1;
            sft +=code[i];
        }
        if(rd==0)
        {
            if(!(rt==0 && sft ==0))
            {
                err_processing(Writeto0,err);
                reg[rd] = 0;
            }
            return ;
        }
        reg[rd] = reg[rt] <<sft;
    }
    else if (func == srl)
    {
        rt = 0;
        for(i=11;i<16;i++)
        {
            rt = rt<<1;
            rt+=code[i];
        }
        rd = 0;
        for(i=16;i<21;i++)
        {
            rd = rd<<1;
            rd +=code[i];
        }
        sft = 0;
        for(i=21;i<26;i++)
        {
            sft = sft <<1;
            sft +=code[i];
        }
        reg[rd] = reg[rt] >>sft;
        if(rd ==0)
        {
            err_processing(Writeto0,err);
            reg[rd] = 0;
        }
    }
    else if (func == sra)
    {
        rt = 0;
        for(i=11;i<16;i++)
        {
            rt = rt<<1;
            rt+=code[i];
        }
        rd = 0;
        for(i=16;i<21;i++)
        {
            rd = rd<<1;
            rd +=code[i];
        }
        sft = 0;
        for(i=21;i<26;i++)
        {
            sft = sft <<1;
            sft +=code[i];
        }
        int tmp = reg[rt];
        tmp = tmp >>sft;
        reg[rd] =tmp;
        if(rd ==0)
        {
            err_processing(Writeto0,err);
            reg[rd] = 0;
        }
    }
    else if (func == jr)
    {
        rs = 0;
        for(i=6;i<11;i++)
        {
            rs = rs <<1;
            rs +=code[i];
        }
        *pc = reg[rs]-unmod_pc-4 ;
    }
}
void instruction_J(int *code,int ct,unsigned *reg, int *pc)
{
    int i;
    unsigned c = 0;
    for(i=6;i<32;i++)
    {
        c= c<<1;
        c += code[i];
    }
    if(ct ==j)
    {
        *pc = ((*pc+4) & j_mask) | (c<<2);
    }
    else if(ct==jal)
    {
        reg[31] = *pc+unmod_pc+4;
        printf("%08x\n",reg[31]);
        *pc = ((*pc+unmod_pc+4)&j_mask)| (c<<2);
        printf("%08x\n",*pc);
    }
}
void instruction_I(int *code,int ct,unsigned *reg, int *pc,unsigned *Dmem,FILE* err)
{
    unsigned rs,rt,eximm;
    int sRs,sRt;
    unsigned imm;
    unsigned sImm;
    getrsrtimm(&rs,&rt,code,&imm);
    if(ct == addi)
    {
        sRs = reg[rs] & mask_31;

        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
        eximm = imm | mask_0;
        int flag = 0;
        reg[rt] = reg[rs] + eximm;
        sRt = (reg[rt] & mask_31)?1:0;
        if(rt==0)
        {
            flag = 1;
            err_processing(Writeto0,err);
        }
        sRt = reg[rt] & mask_31;
        if(sRs == (eximm & mask_31) && sRs !=sRt)
        {
            err_processing(NumOver,err);
        }
         if(flag)   reg[rt] = 0;
    }
    else if(ct == addiu)
    {
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
        eximm = imm | mask_0;

        reg[rt] = reg[rs] + eximm;
        if(rt==0)
        {
            err_processing(Writeto0,err);
            reg[rt] = 0;
        }
    }
    else if(ct == lw)
    {
        int flag = 0;
        if(rt==0)
        {
            flag = 1;
            err_processing(Writeto0,err);
        }
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        unsigned addr;//sign handle
        addr = imm + reg[rs];
        unsigned sAddr;
            sRs = (reg[rs] & mask_31)?1:0;
            sImm = (eximm & mask_31)?1:0;
        addr = eximm + reg[rs];
         sAddr =(addr & mask_31)?1:0;

        if(sRs == sImm && sAddr!=sRs)
            err_processing(NumOver,err);
        if(addr >=1021 || addr%4)
        {
            if(addr >=1021)
            err_processing(MemaddrOver,err);
            if(addr%4)
            err_processing(DataMis,err);
            err_handle = 1;
            return ;
        }

        {
            reg[rt] = 0;
            int i;
            for(i=0;i<32;i++)
            {
                reg[rt] = reg[rt] <<1;
                reg[rt] += Dmem[addr*8+i];
            }
        }
        if(flag ) reg[rt] = 0;
    }
    else if(ct == lh)
    {
        int flag = 0;
        if(rt==0)
        {
            flag = 1;
            err_processing(Writeto0,err);
        }
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        unsigned addr;//sign handle
        unsigned sAddr;
            sRs =(reg[rs] & mask_31)?1:0;
            sImm =(eximm & mask_31)? 1:0;
        addr = eximm + reg[rs];
         sAddr =(addr & mask_31)?1:0;
        if(sRs == sImm && sAddr!=sRs)
        {
            err_processing(NumOver,err);
        }
        if(addr >=1023 || addr%2)
        {
            if(addr >=1023)
            err_processing(MemaddrOver,err);
            if(addr%2)
                err_processing(DataMis,err);
            err_handle = 1;
            return ;
        }

        {
            reg[rt] = 0;
            int i;
            for(i=0;i<16;i++)
            {
                reg[rt] =reg[rt] <<1;
                reg[rt] += Dmem[addr*8+i];
            }
            if(reg[rt] & 0x8000) reg[rt] = reg[rt] | 0xFFFF0000;
        }
        if(flag) reg[rt] = 0;
    }
    else if(ct == lhu)
    {
        int flag = 0;
        if(rt==0)
        {
            flag = 1;
            err_processing(Writeto0,err);
        }
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        unsigned addr;//sign handle
        unsigned sAddr;
            sRs =(reg[rs] & mask_31)?1:0;
            sImm =(eximm & mask_31)? 1:0;
        addr = eximm + reg[rs];
         sAddr =(addr & mask_31)?1:0;
        if(sRs == sImm && sAddr!=sRs)
        {
            err_processing(NumOver,err);
        }
        if(addr >=1023 || addr%2)
        {
            if(addr >=1023)
            err_processing(MemaddrOver,err);
            if(addr%2)
                err_processing(DataMis,err);
            err_handle = 1;
            return ;
        }

        {
            reg[rt] = 0;
            int i;
            for(i=0;i<16;i++)
            {
                reg[rt] =  reg[rt] <<1;
                reg[rt] += Dmem[addr*8+i];
            }
        }
        if(flag) reg[rt] = 0;
    }
    else if(ct == lb)
    {
        int flag = 0;
        if(rt==0)
        {
            flag = 1;
            reg[rt] = 0;
            err_processing(Writeto0,err);
        }
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        unsigned addr;//sign handle
        unsigned sAddr;
            sRs =(reg[rs] & mask_31)?1:0;
            sImm =(eximm & mask_31)? 1:0;
        addr = eximm + reg[rs];
         sAddr =(addr & mask_31)?1:0;
        if(sRs == sImm && sAddr!=sRs)
        {
            err_processing(NumOver,err);
        }
        if(addr >=1024)
        {
            if(addr >=1024)
            err_processing(MemaddrOver,err);
            err_handle = 1;
            return ;
        }
        addr = eximm + reg[rs];
        {
            int tmp = 0;
            int i;
            for(i=0;i<8;i++)
            {
               tmp =tmp<<1;
               tmp += Dmem[addr*8+i];
            }
            reg[rt] = tmp;
            if(tmp & 0x80) reg[rt] = reg[rt] | 0xFFFFFF00;
        }
        if(flag) reg[rt] = 0;
    }
    else if(ct == lbu)
    {
        int flag = 0;
        if(rt==0)
        {
            flag = 1;
            reg[rt] = 0;
            err_processing(Writeto0,err);
        }
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        unsigned addr;//sign handle
        unsigned sAddr;
            sRs =(reg[rs] & mask_31)?1:0;
            sImm =(eximm & mask_31)? 1:0;
        addr = eximm + reg[rs];
         sAddr =(addr & mask_31)?1:0;
        if(sRs == sImm && sAddr!=sRs)
        {
            err_processing(NumOver,err);
        }
        if(addr >=1024)
        {
            err_processing(MemaddrOver,err);
            err_handle = 1;
            return ;
        }

        {
            reg[rt] = 0;
            int i;
            for(i=0;i<8;i++)
            {
                reg[rt] =reg[rt] <<1;
                reg[rt] += Dmem[addr*8+i];
            }
        }
        if(flag) reg[rt] = 0;
    }
    else if(ct == sw)
    {
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        unsigned addr;//sign handle
        addr = eximm + reg[rs];
        unsigned sAddr;
            sRs =(reg[rs] & mask_31)?1:0;
            sImm =(eximm & mask_31)? 1:0;
        addr = eximm + reg[rs];
         sAddr =(addr & mask_31)?1:0;
        if(sRs == sImm && sAddr!=sRs)
        {
            err_processing(NumOver,err);
        }
        if(addr >=1021 || addr%4)
        {
            if(addr >=1021)
            err_processing(MemaddrOver,err);
            if(addr%4)
                err_processing(DataMis,err);
            err_handle = 1;
            return ;
        }
        {
            int i;
            int tmp = reg[rt];
            for(i=0;i<32;i++)
            {
                if(tmp & masks[31-i])
                {
                    tmp -=masks[31-i];
                    Dmem[addr*8+i] = 1;
                }
                else
                {
                    Dmem[addr*8+i] = 0;
                }
            }
        }
    }
    else if(ct == sh)
    {
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        unsigned addr;//sign handle
        unsigned sAddr;
            sRs =(reg[rs] & mask_31)?1:0;
            sImm =(eximm & mask_31)? 1:0;
        addr = eximm + reg[rs];
         sAddr =(addr & mask_31)?1:0;
        if(sRs == sImm && sAddr!=sRs)
        {
            err_processing(NumOver,err);
        }
        addr = eximm + reg[rs];
        if(addr >=1023 || addr%2)
        {
            if(addr >=1023)
            err_processing(MemaddrOver,err);
            if(addr%2)
                err_processing(DataMis,err);
            err_handle = 1;
            return ;
        }
        {
            int i;
            int tmp = reg[rt] & 0x0000FFFF;
            for(i=0;i<16;i++)
            {
                if(tmp & masks[15-i])
                {
                    tmp -=masks[15-i];
                    Dmem[addr*8+i] = 1;
                }
                else
                {
                    Dmem[addr*8+i] = 0;
                }
            }
        }
    }
    else if(ct == sb)
    {
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        unsigned addr;//sign handle
        unsigned sAddr;
            sRs =(reg[rs] & mask_31)?1:0;
            sImm =(eximm & mask_31)? 1:0;
        addr = eximm + reg[rs];
         sAddr =(addr & mask_31)?1:0;
        if(sRs == sImm && sAddr!=sRs)
        {
            err_processing(NumOver,err);
        }
        if(addr >=1024)
        {
            if(addr >=1024)
            err_processing(MemaddrOver,err);
            err_handle = 1;
            return ;
        }
        addr = eximm + reg[rs];
        {
            int i;
            int tmp = reg[rt] & 0x000000FF;
            for(i=0;i<8;i++)
            {
                if(tmp & masks[7-i])
                {
                    tmp -=masks[7-i];
                    Dmem[addr*8+i] = 1;
                }
                else
                {
                    Dmem[addr*8+i] = 0;
                }
            }
        }
    }
    else if(ct == lui)
    {
        reg[rt] = imm <<16;
        if(rt==0)
        {
            err_processing(Writeto0,err);
            reg[rt] = 0;
        }
    }
    else if(ct == andi)
    {
        reg[rt] = reg[rs] & imm;
        if(rt==0)
        {
            err_processing(Writeto0,err);
            reg[rt] = 0;
        }
    }
    else if(ct == ori)
    {

        reg[rt] = reg[rs] | imm;
        if(rt==0)
        {
            err_processing(Writeto0,err);
            reg[rt] = 0;
        }
    }
    else if(ct == nori)
    {
        reg[rt] = ~(reg[rs] | imm);
        if(rt==0)
        {
            err_processing(Writeto0,err);
            reg[rt] = 0;
        }
    }
    else if(ct == slti )
    {
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        int intImm = eximm;
        int sRs = reg[rs];
         reg[rt] = sRs < intImm;
        if(rt==0)
        {
            err_processing(Writeto0,err);
            reg[rt] = 0;
        }
    }
    else if(ct == beq)
    {
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        if(reg[rs]==reg[rt])
        {
            int x = eximm;
            x = x<<2 ;
            *pc +=x;
        }
        if(*pc >=1020)
        {
             err_processing(NumOver,err);
             err_processing(MemaddrOver,err);
             err_processing(DataMis,err);
             err_handle  = 1;
        }
    }
    else if(ct == bne)
    {
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        if(reg[rs]!=reg[rt])
        {
            int x = eximm;
            x = x<<2 ;
            *pc =*pc + x;
        }
        if(*pc >=1020)
        {
             err_processing(NumOver,err);
             err_processing(MemaddrOver,err);
             err_processing(DataMis,err);
             err_handle  = 1;
        }
    }
    else if(ct == bgtz)
    {
        if(imm & mask_15)
            eximm = imm | mask_4F;
        else
            eximm = imm | mask_0;
        sRs = (reg[rs] & mask_31) ? 1:0;
        if(reg[rs]>0 && sRs==0)
        {
            int x = eximm;
            x = x<<2 ;
            *pc = *pc  +x;
        }
    }
}
void getrsrtrd(unsigned *rs,unsigned *rt,unsigned *rd,int *code)
{
    int i ;
    *rs = 0,*rt = 0,*rd = 0;
    for(i=6;i<11;i++)
    {
        *rs = *rs <<1;
        *rs +=code[i];
    }
    for(i=11;i<16;i++)
    {
        *rt = *rt<<1;
        *rt +=code[i];
    }
    for(i=16;i<21;i++)
    {
        *rd = *rd<<1;
        *rd +=code[i];
    }
}
void getrsrtimm(unsigned *rs,unsigned *rt,int *code,unsigned *imm)
{
    int i ;
    *rs = 0,*rt = 0,*imm = 0;
    for(i=6;i<11;i++)
    {
        *rs = *rs <<1;
        *rs +=code[i];
    }
    for(i=11;i<16;i++)
    {
        *rt = *rt<<1;
        *rt +=code[i];
    }
    for(i=16;i<32;i++)
    {
        *imm = *imm<<1;
        *imm +=code[i];
    }
}
void err_processing(int errtype,FILE *err)
{
        if(errtype==Writeto0)
        {
            fprintf(err, "In cycle %d: Write $0 Error\n", cycle);
        }
        else if(errtype==NumOver)
        {
            fprintf(err,"In cycle %d: Number Overflow\n",cycle);
        }
        else if(errtype ==MemaddrOver)
        {
             fprintf(err, "In cycle %d: Address Overflow\n", cycle);
        }
        else if(errtype==DataMis)
        {
            fprintf(err, "In cycle %d: Misalignment Error\n", cycle);
        }
}
