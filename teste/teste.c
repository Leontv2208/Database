#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define N 500


    struct entrada{
        char user[10];
        char password[10];
    };

    struct usuario {
        char login[10];
        char senha[10];
        char nome[30];
    };

int main(int argc, char** argv){
    struct entrada Entry;
    struct usuario User[N];
    FILE *data, *time;

    clock_t start, end;
    double cpu_time_used;


        //Abre o arquivo database.dat para leitura, e verifica se o arquivo pode ser aberto
        data = fopen("../../database.dat", "r");
        if (data == NULL) {
            printf("Erro! Arquivo não pode ser aberto\n");
            return -1;
        }
        time = fopen("../teste.txt", "w");
        if (time == NULL) {
            printf("Erro! Arquivo não pode ser aberto\n");
            return -1;
        }

        //Lê o arquivo e armazena na struct User
        for (int i = 0; i < N; ++i) {
            fscanf(data, "%10c", User[i].login);
            fscanf(data, "%10c", User[i].senha);
            fscanf(data, "%30c", User[i].nome);
        }

    for (int i = 0; i < N; ++i) {
        int j=0;

        //Inicia a contagem de tempo CPU
        start = clock();

        //Procura pelo nome de usuario e senha no banco de dados
        while ((strcmp(User[j].login, User[i].login) != 0 && strcmp(User[j].senha, User[i].senha) != 0)&&(j<N)) {
            j++;
        }

            printf("Bem vindo(a), %s\n", User[j].nome);
            end=clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            fprintf(time,"%s || %s || %s || %f\n", User[j].login, User[j].senha, User[j].nome, cpu_time_used );
    }
}