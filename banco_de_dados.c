#include "banco_de_dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 500

int main(int argc, char** argv){

    struct usuario{
        char login[10];
        char senha[10];
        char nome[30];
    } User[N];
    FILE *d;


    d = fopen("../database.dat", "r");
    if (d == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }

    for (int i = 0; i < N; ++i) {
        fscanf(d, "%10c", User[i].login);
        fscanf(d, "%10c", User[i].senha);
        fscanf(d, "%30c", User[i].nome);

        printf("%s ", User[i].login);
        printf("%s ", User[i].senha);
        printf("%s\n", User[i].nome);
    }







    return 0;
}