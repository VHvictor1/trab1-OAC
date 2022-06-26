// Nome: Victor Hugo da Silva de Oliveira.
// Matrícula: 190129794.
// Description: Trabalho 1 de OAC.
#include <stdint.h> 
#include <stdio.h>
// Definição do tamanho máximo da memória e do nosso vetor de memória.{linhas: 8-9}
#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];
// Criação da função loadword utilizada para mostrar uma palavra de 8 bytes no nosso array,
// lembrando que o Endereço é a soma da variável address e da constante (kte) e o primeiro
// bit da nossa palavra vai ser um número divisível por 4 em todas as vezes.
// {linhas: 13-23}.
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
// Criação da função loadbyte utilizada para mostrar um byte no nosso array, nesse caso
// fizemos um ponteiro (pointer) que ira armazenar o valor do array memória e utilizamos
// outra variável para armazenar o valor que está em pointer. {linhas: 28-35}.
int32_t lb(uint32_t address, int32_t kte)
{
    int8_t *pointer;
    int32_t lastByte;
    pointer = (int8_t *)mem;
    lastByte = *(pointer + (address + kte));
    return lastByte;
};
// Criação da função loadbyteUnitary utilizada para mostrar um byte no nosso array, nesse caso
// fizemos um ponteiro (pointer) que ira armazenar o valor do array memória e utilizamos
// outra variável para armazenar o valor que está em pointer, porém neste caso precisamos
// retornar o valor sem o sinal então criamos uma máscara para fazer essa função.
// {linhas: 41-49}.
int32_t lbu(uint32_t address, int32_t kte)
{
    int8_t *pointer;
    int32_t lastByte;
    pointer = (int8_t *)mem;
    lastByte = *(pointer + (address + kte));
    lastByte = lastByte & 0x000000ff;
    return lastByte;
};
// Criação da função storeWord utilizada para adicionar uma palavra no nosso array, porém temos de checar se o nosso
// endereço é divisível por 4 poís a primeira posição de cada palavra é um número divisível por 4, assim escrevemos
// na posição de endereço dividida por 4.
// {linhas: 54-64}.
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
// Criação da função storebit utilizada para adicionar um bit no nosso array, assim criamos um ponteiro para apontar o
// local na memória e falamos que o endereço do nosso ponteiro vai ser o endereço da memória mais o address mais a 
// constante (kte) assim falamos que o valor do pointer é igual ao nosso dado a ser armazenado.
// na posição de endereço dividida por 4.
// {linhas: 70-76}.
void sb(uint32_t address, int32_t kte, int8_t dado)
{
    int8_t *pointer;
    pointer = (int8_t *)mem;
    pointer = (pointer + (address + kte));
    *pointer = dado;
}; 
// Função principal onde possui nossas variáveis b0 - b11 (bit 0 - bit 11), recebe os valores do usuário e executa as
// funções pedidas na ordem pedida.
// {linhas: 80-116}.
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
    sb(4, 0, b4);
    sb(4, 1, b5);
    sb(4, 2, b6);
    sb(4, 3, b7);
    sw(8, 0, b8);
    sw(12, 0, b9);
    sw(16, 0, b10);
    sw(20, 0, b11);

    printf("%.08x\n", mem[0]);
    printf("%.08x\n", mem[1]);
    printf("%.08x\n", mem[2]);
    printf("%.08x\n", mem[3]);
    printf("%.08x\n", mem[4]);
    printf("%.08x\n", mem[5]);
    printf("%.8x\n", lb(4, 0));
    printf("%.8x\n", lbu(4, 0));
    printf("%.8x\n", lw(12, 0));
    printf("%.8x\n", lw(16, 0));
    printf("%.8x\n", lw(20, 0));
};
// ©Código feito por Victor Hugo da Silva de Oliveira, não dever ser copiado, deve ser usado apenas para estudos.