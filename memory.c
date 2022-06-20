#include <stdint.h>;
#include <stdio.h>;
#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];

int main(){}

int32_t lw(uint32_t address, int32_t kte)
{
    if((address + kte) % 4 == 0){
        return mem[(address+kte)/4];
    }
    else{
        print("endereço errado");
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
    return lastByte = lastByte & 0x000000ff;
};

void sw(uint32_t address, int32_t kte, int32_t dado)
{
     if((address + kte) % 4 == 0){
        mem[(address+kte)/4] = dado;
    }
    else{
        print("endereço errado");
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