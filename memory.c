#include <stdint.h> 
#include <stdio.h>
#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];

int32_t lw(uint32_t address, int32_t kte)
{
    if ((address + kte) % 4 == 0)
    {
        return mem[((address + kte) / 4)];
    }
    else
    {
        printf("Endereço errado");
        return 0;
    }
};

int32_t lb(uint32_t address, int32_t kte)
{
    int8_t *pointer;
    int32_t lastByte;
    pointer = (int8_t *)mem;
    lastByte = *(pointer + (address + kte));
    return lastByte;
};

int32_t lbu(uint32_t address, int32_t kte)
{
    int8_t *pointer;
    int32_t lastByte;
    pointer = (int8_t *)mem;
    lastByte = *(pointer + (address + kte));
    lastByte = lastByte & 0x000000ff;
    return lastByte;
};

void sw(uint32_t address, int32_t kte, int32_t dado)
{
    if ((address + kte) % 4 == 0)
    {
        mem[(address + kte) / 4] = dado;
    }
    else
    {
        printf("Endereço errado");
    }
};

void sb(uint32_t address, int32_t kte, int8_t dado)
{
    int8_t *pointer;
    pointer = (int8_t *)mem;
    pointer = (pointer + (address + kte));
    *pointer = dado;
}; 


int main()
{
    int8_t b0, b1, b2, b3, b4, b5, b6, b7;
    int32_t b8, b9, b10, b11;

    scanf("%hhx, %hhx, %hhx, %hhx", &b0, &b1, &b2, &b3);
    scanf("%hhx, %hhx, %hhx, %hhx", &b4, &b5, &b6, &b7);
    scanf("%x", &b8);
    scanf("%x", &b9);
    scanf("%x", &b10);
    scanf("%x", &b11);

    sb(0, 0, b0);
    sb(0, 1, b1);
    sb(0, 2, b2);
    sb(0, 3, b3);
    printf("%.08x\n", mem[0]);
    sb(4, 0, b4);
    sb(4, 1, b5);
    sb(4, 2, b6);
    sb(4, 3, b7);
    printf("%.08x\n", mem[1]);
    sw(8, 0, b8);
    printf("%.08x\n", mem[2]);
    sw(12, 0, b9);
    printf("%.08x\n", mem[3]);
    sw(16, 0, b10);
    printf("%.08x\n", mem[4]);
    sw(20, 0, b11);
    printf("%.08x\n", mem[5]);
    printf("%.8x\n", lb(4, 0));
    printf("%.8x\n", lbu(4, 0));
    printf("%.8x\n", lw(12, 0));
    printf("%.8x\n", lw(16, 0));
    printf("%.8x\n", lw(20, 0));
};

