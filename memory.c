#include <stdint.h>
#include <stdio.h>
#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];

int main(){
    int b0, b1, b2, b3, b4, b5, b6, b7;
    int b8, b9, b10, b11;

    scanf("%hhx, %hhx, %hhx, %hhx", &b0, &b1, &b2, &b3);
    scanf("%hhx, %hhx, %hhx, %hhx", &b4, &b5, &b6, &b7);
    scanf("%X", &b8);
    scanf("%X", &b9);
    scanf("%X", &b10);
    scanf("%X", &b11);


    sb(0, 0, b0); sb(0, 1, b1); sb(0, 2, b2); sb(0, 3, b3);
    printf("mem[0] = %.08X \n",mem[0]);
    sb(4, 0, b4); sb(4, 1, b5); sb(4, 2, b6); sb(4, 3, b7);
	printf("mem[1] = %.08X \n",mem[1]);
    sw(8, 0, b8);
	printf("mem[2] = %.08X \n",mem[2]);
    sw(12, 0, b9);
	printf("mem[3] = %.08X \n",mem[3]);
    sw(16, 0, b10);
	printf("mem[4] = %.08X \n",mem[4]);
    sw(20, 0, b11);
	printf("mem[5] = %.08X \n",mem[5]);
    printf("%.8X \n",lb(4,0));
    printf("%.8X \n",lbu(4,0));
    printf("%.8X \n",lw(12,0));
    printf("%.8X \n",lw(16,0));
    printf("%.8X \n",lw(20,0));


//     printf("------------------------------------------------------- \n");
//     printf("%.8X \n",lb(4,0));
//     printf("%.8X \n",lb(4,1));
//     printf("%.8X \n",lb(4,2));
//     printf("%.8X \n",lb(4,3));
//     printf("%.8X \n",lbu(4,0));
//     printf("%.8X \n",lbu(4,1));
//     printf("%.8X \n",lbu(4,2));
//     printf("%.8X \n",lbu(4,3));
//     printf("%.8X \n",lw(12,0));
//     printf("%.8X \n",lw(16,0));
//     printf("%.8X \n",lw(20,0));

}

int32_t lw(uint32_t address, int32_t kte)
{
    if((address + kte) % 4 == 0){
        return mem[((address+kte)/4)];
    }
    else{
        printf("Endereço errado");
    }
};

int32_t lb(uint32_t address, int32_t kte)
{
    int8_t * pointer; 
    int32_t lastByte;
    pointer = (int8_t *)mem;
    lastByte = *(pointer + (address + kte));
    return lastByte;
};

int32_t lbu(uint32_t address, int32_t kte)
{
    int8_t * pointer; 
    int32_t lastByte;
    pointer = (int8_t *)mem;
    lastByte = *(pointer + (address + kte));
    lastByte = lastByte & 0x000000ff;
    return lastByte;
};

void sw(uint32_t address, int32_t kte, int32_t dado)
{
     if((address + kte) % 4 == 0){
        mem[(address+kte)/4] = dado;
    }
    else{
        printf("Endereço errado");
    }
}; 

void sb(uint32_t address, int32_t kte, int8_t dado)
{
    int8_t * pointer; 
    int32_t lastByte;
    pointer = (int8_t *)mem;
    pointer = (pointer + (address + kte));
    *pointer = dado;
}; 