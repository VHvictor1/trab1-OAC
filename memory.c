#include <stdint.h>;
#include <stdio.h>;
#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];

int main(){
    int newValue;
    int address;
    int kte;
    scanf("%hhx", &newValue );
    sb(address,kte,newValue);
    sw(address,kte,newValue);
    lb(address, kte);
    lw(address, kte);
    lbu(address, kte);
}

int32_t lw(uint32_t address, int32_t kte)
{
    if((address + kte) % 4 == 0){
        printf("%08x", &mem[(address+kte)/4]);
        return 0;
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
    printf("%08x", &lastByte);
    return 0;
};

int32_t lbu(uint32_t address, int32_t kte)
{
    int8_t * pointer; 
    int32_t lastByte;
    pointer = (int8_t *)mem;
    lastByte = *(pointer + (address + kte));
    lastByte = lastByte & 0x000000ff;
    printf("%08x", &lastByte);
    return 0;
};

void sw(uint32_t address, int32_t kte, int32_t dado)
{
     if((address + kte) % 4 == 0){
        mem[(address+kte)/4] = dado;
        return 0;
    }
    else{
        printf("Endereço errado");
        return 0;
    }
}; 

void sb(uint32_t address, int32_t kte, int8_t dado)
{
    int8_t * pointer; 
    int32_t lastByte;
    pointer = (int8_t *)mem;
    pointer = (pointer + (address + kte));
    *pointer = dado;
    return 0;
}; 