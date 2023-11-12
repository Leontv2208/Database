#include "verificador_database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    struct entry Entry;
    struct usuario Usuario[N];
    FILE *ptr;

    //Abre o arquivo database.dat para leitura, e verifica se o arquivo pode ser aberto
    ptr = fopen("../database.dat", "r");
    if (ptr == NULL)
    {
        printf("Error! Could not open file\n");
        return 1;
    }

    //Lê o arquivo e armazena na struct Usuario
    read_file(ptr, Usuario);

    //Entrada de usuário e senha do prompt
    printf("Nome de Usuário: ");
    scanf("%s", &Entry.user);
    printf("Senha: ");
    scanf("%s", &Entry.password);

    //teste
    printf("%s\n", Entry.user);
    printf("%s\n", Entry.password);


    search(Usuario, Entry);





    return 0;
}