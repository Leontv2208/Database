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
    FILE *data;

    //Abre o arquivo database.dat para leitura, e verifica se o arquivo pode ser aberto
    data = fopen("../database.dat", "r");
    if (data == NULL) {
        printf("Erro! Arquivo não pode ser aberto\n");
        return -1;
    }

    //Lê o arquivo e armazena na struct User
    for (int i = 0; i < N; ++i) {
        fscanf(data, "%10c", User[i].login);
        fscanf(data, "%10c", User[i].senha);
        fscanf(data, "%30c", User[i].nome);
    }

    while(1) {
        int j=0;

        //Entrada de usuário e senha do prompt
        printf("Nome de Usuario: ");
        scanf("%s", &Entry.user);
        printf("Senha: ");
        scanf("%s", &Entry.password);

        //Procura pelo nome de usuario e senha no banco de dados
        while ((strcmp(User[j].login, Entry.user) != 0 && strcmp(User[j].senha, Entry.password) != 0)&&(j<N)) {
            j++;
        }
        if (j < N) {
            printf("Bem vindo(a), %s\n", User[j].nome);
            return 0;
        } else {
            printf("Nome de usuario ou senha incorretos\n\n");
        }
    }
}