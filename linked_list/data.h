#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50

typedef struct Pessoas{
    char nome[MAX_CHAR];
    int idade;
    float altura;
    struct Pessoas *next;
}Pessoa;

Pessoa *InitPessoa();
Pessoa *AddPessoa(Pessoa *pessoa, char *nome, int idade, float altura);
void RemovePessoa(Pessoa *pessoa, char *nome);
void SearchPessoa(Pessoa *pessoa);
void DestroyPessoa(Pessoa *pessoa);
void ListPessoa(Pessoa *pessoa);