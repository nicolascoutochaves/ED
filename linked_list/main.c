#include "data.h"
int main(){
    Pessoa *colorados;
    Pessoa *gremistas;
    gremistas = InitPessoa();
    gremistas = AddPessoa(gremistas, "Geromel", 35, 1.83);
    colorados = InitPessoa();
    colorados = AddPessoa(colorados, "D'Alessandro", 39, 1.78);

    printf("Endereco de gremistas: 0x%p\n", gremistas);
    printf("Endereco de colorados: 0x%p\n", colorados);

    AddPessoa(gremistas, "Alisson", 28, 1.75);
    AddPessoa(gremistas, "Brenno", 22, 1.83);
    AddPessoa(gremistas, "Cortez", 34, 1.75);
    AddPessoa(gremistas, "Darlan", 23, 1.75);
    AddPessoa(gremistas, "Diego Souza", 35, 1.83);

    AddPessoa(colorados, "Cuesta", 32, 1.83);
    AddPessoa(colorados, "Edenilson", 31, 1.75);
    AddPessoa(colorados, "Praxedes", 21, 1.75);
    AddPessoa(colorados, "Rodinei", 29, 1.75);
    AddPessoa(colorados, "Thiago Galhardo", 31, 1.75);
    AddPessoa(colorados, "Victor Cuesta", 32, 1.83);
    AddPessoa(colorados, "Yuri Alberto", 20, 1.75);
    AddPessoa(colorados, "Zé Gabriel", 23, 1.75);
    AddPessoa(colorados, "Zé Ricardo", 49, 1.75);
    AddPessoa(colorados, "Zé Welison", 27, 1.75);


    ListPessoa(colorados);
    ListPessoa(gremistas);
    //free(colorados);
    //colorados = NULL;
    return 0;
}