#include "data.h"
Pessoa *InitPessoa(){
    return NULL;
}
Pessoa *AddPessoa(Pessoa *pessoa, char *nome, int idade, float altura) {
    if (pessoa == NULL) {
        pessoa = calloc(sizeof(Pessoa), 1);
        if(pessoa == NULL) {
            printf("Erro ao alocar memoria\n");
            return NULL;
        }
        else {
            printf("adding person at 0x%p\n", pessoa);
            strcpy(pessoa->nome, nome);
            pessoa->idade = idade;
            pessoa->altura = altura;
            pessoa->next = NULL;                 
        }
    } else {
        pessoa->next = AddPessoa(pessoa->next, nome, idade, altura);
    }
    return pessoa;
}
void RemovePessoa(Pessoa *pessoa, char *nome) {
    puts("Inside RemovePessoa");
    if (pessoa == NULL) {
        printf("Pessoa nao encontrada\n");
        return;
    }
    if (strcmp(pessoa->next->nome, nome) == 0) {
        Pessoa *temp = pessoa->next;
        pessoa->next = pessoa->next->next;
        free(temp);
    } else {
        RemovePessoa(pessoa->next, nome);
    }
}
void ListPessoa(Pessoa *pessoa) {
    puts("Inside ListPessoa");
    if (pessoa == NULL) {
        printf("Lista vazia (end 0x%p)\n", pessoa);
        return;
    }
    Pessoa *temp = pessoa;
    while (temp != NULL) {
        printf("Nome: %s\n", temp->nome);
        printf("Idade: %d\n", temp->idade);
        printf("Altura: %f\n", temp->altura);
        temp = temp->next;
    }
}