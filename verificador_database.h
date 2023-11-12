//
// Created by aluno on 10/11/23.
//

#ifndef DATABASE_VERIFICADOR_DATABASE_H
#define DATABASE_VERIFICADOR_DATABASE_H
#include <stdio.h>
#include <string.h>

#define N 500

typedef struct entry{
    char user[10];
    char password[10];
} entry;

typedef struct usuario {
    char login[10];
    char senha[10];
    char nome[30];
} usuario;

void read_file(FILE *ptr,struct usuario a[]){
    for (int i = 0; i < N; ++i) {
        fscanf(ptr, "%10c", a[i].login);
        fscanf(ptr, "%10c", a[i].senha);
        fscanf(ptr, "%30c", a[i].nome);
    }
}

void search(struct usuario user[], struct entry entrada){
    for (int j = 0; j < N; ++j) {
        if(strcmp(user[j].login, entrada.user) == 0 && strcmp(user[j].senha, entrada.password) == 0){
            printf("Bem vindo(a), %s\n",user[j].nome);
        } else if (j = N){
            printf("Nome de usuário ou senha incorretos\n");

        }
    }
}


#endif //DATABASE_VERIFICADOR_DATABASE_H
