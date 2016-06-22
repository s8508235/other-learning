#include "stdio.h"
#include "stdlib.h"
#include "instruction.h"
int mask[8];
unsigned reg[32];

FILE *iImageData,*dImageData;
int main()
{
    iImageData = fopen("testing/tests/102060020_03/iimage.bin","rb");//102062104_01 102062111 102062202_01
    dImageData = fopen("testing/tests/102060020_03/dimage.bin","rb");//102070028_01
    int isize,dsize;
    fseek(iImageData,0,SEEK_END);
    isize = ftell(iImageData);
    fseek(iImageData,0,SEEK_SET);

    fseek(dImageData,0,SEEK_END);
    dsize = ftell(dImageData);
    fseek(dImageData,0,SEEK_SET);
    printf("%08x %08x\n",isize,dsize);
    if(isize >=1032) isize = 1032;
    if(dsize >=1032) dsize = 1032;
    int i;
    char ibuffer[1032],dbuffer[1032];
    unsigned int iimage[isize],dimage[dsize];
    for(i=0;i<isize;i++)
    {
        ibuffer[i] = 0;
        iimage[i] = 0;
    }

    for(i=0;i<dsize;i++)
    {
        dbuffer[i] = 0;
        dimage[i] = 0;
    }

    for(i=0;i<32;i++)
    {
        reg[i] = 0;
    }
    for(i=0;i<8;i++)
    {
       mask[i] = 1<<i;
    }
    int ire,dre;
    dre=fread(&dbuffer,1,dsize,dImageData);
    ire=fread(&ibuffer,1,isize,iImageData);
    for(i=0;i<isize;i++)
    {
       iimage[i] =(unsigned char) ibuffer[i];
    }
    for(i=0;i<dsize;i++)
    {
        dimage[i] =(unsigned char) dbuffer[i]-'\0';
    }
    fclose(iImageData);
    fclose(dImageData);
    unsigned int pc =0,sp = 0;
    unsigned int num_I = 0,num_D = 0;
    for(i=0;i<4;i++)
    {
        pc = pc<<8;
        pc +=iimage[i];
        num_I = num_I <<8;
        num_I += iimage[i+4];

        sp = sp<<8;
        sp+=dimage[i];
        num_D = num_D<<8;
        num_D +=dimage[i+4];
    }
    unsigned int Imem[8192],Dmem[8192];
    for(i=0;i<8192;i++)
    {
        Imem[i] = 0;
        Dmem[i] = 0;
    }
    int i_cnt = 0,d_cnt = 0,k;
    for(i=8;i<8+4*num_I;i++)
    {
        for(k=0;k<8;k++,i_cnt++)
        {
            if(iimage[i] & mask[7-k])
            {
                iimage[i] -=mask[7-k]+'\0';
                Imem[i_cnt] = 1;
            }
        }
    }
    for(i=8;i<8+4*num_D;i++)
    {
        for(k=0;k<8;k++,d_cnt++)
        {
            if(dimage[i] & mask[7-k])
            {
                dimage[i] -=mask[7-k]+'\0';
                Dmem[d_cnt] = 1;
            }
        }
    }printf("%08x %08x %08x\n",num_I,num_D,sp);
    reg[$sp] = sp;
	int asscode[32];
    unsigned int cnt  = 0;
    FILE *out = fopen("snapshot.rpt","wb");
    FILE *err = fopen("error_dump.rpt","wb");
     int currpc =  0;
	for(k=0;k<num_I;)
	{
        fprintf(out,"cycle %u\n",cnt++);
        for(i=0;i<32;i++)
            asscode[i] = Imem[i+32*k];
        for(i=0;i<32;i++)
        {
            if(i<10)
            fprintf(out,"$0%d: 0x",i);
            else
            fprintf(out,"$%d: 0x",i);
            fprintf(out,"%08X\n",reg[i]);
        }
        fprintf(out,"PC: 0x");
        fprintf(out,"%08X\n\n\n",pc+currpc);
        int temp_pc = currpc;
        int type = -1;
        {
	    if(currpc>=0)
            type = instruction_operation(asscode,reg,cnt,&currpc,Dmem,pc,err);
        }
        if(currpc <0 && type!=2)
        {
            if(currpc + pc <0)
            {
                currpc =  temp_pc +4;
            }
            else currpc +=4;
            if(currpc <0) k = 0;
            else k = currpc/4;
        }
        else if(type== 3) break;
        else if(type ==2)
        {printf("%08x %08x\n",currpc , pc);
            if(currpc>pc)
            {
                currpc -=pc;
            }
            else if(currpc <0)
            {
                currpc =temp_pc + 4 ;
            }
            else if(currpc ==0 )
            {
                currpc = -pc;
                k = 0;
            }
            else if( currpc ==pc )
            {
                currpc = 0;
                k = 0;
            }
            else if(currpc <pc)
            {
                currpc -=pc ;
                k = 0;
            }

            if(currpc >0)
            k = currpc/4;
        }
        else
        {
            currpc+=4;
            k = currpc/4;
        }
	}
    fclose(out);
    return 0;
}
