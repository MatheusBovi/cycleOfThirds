#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"


// Variáveis globáis
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;

// criação de funções fora do int main(){}
void abertura() {
    printf("**********************\n");
    printf("*   Jogo de Forca   *\n");
    printf("**********************\n\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
    chutesDados++;

}

void desenhaforca() {

    int erros = chuteserrados();

    printf("  _______        \n");
    printf(" |/      |       \n");

    printf(" |      %c%c%c   \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c   \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c      \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c    \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |               \n");
    printf("_|___            \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavraSecreta); i++) {

        int achou = jachutou(palavraSecreta[i]);

        if(achou) {
            printf("%c ", palavraSecreta[i]);

        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void adicionapalavra() {

    char quer;

    printf("Voce deseja adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &quer);

    if(quer == 'S') {

        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");

        if(f == 0) {
            printf("Desculpe, banco de dados nao disponivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }

}

void escolhepalavra() {

    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Desculpe, banco de dados nao disponivel\n\n");
        exit(1);
    }

    int qtdepalavras;
    fscanf(f, "%d", &qtdepalavras);

    srand(time(0));
    int randomico = rand() % qtdepalavras;

    for(int i = 0; i <= randomico; i++) {

        fscanf(f, "%s", palavraSecreta);

    }

    fclose(f);
}

int acertou() {

    for(int i = 0; i < strlen(palavraSecreta); i++) {

        if(!jachutou(palavraSecreta[i])) {

            return 0;

        }

    }

    return 1;

}

int chuteserrados() {

    int erros = 0;

    for(int i = 0; i < chutesDados; i++) {
        int existe = 0;

        for(int j = 0; j < strlen(palavraSecreta); j++ ) {
            if(chutes[i] == palavraSecreta[j]) {

                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
        
    }

    return erros;

}

int enforcou() {


    return chuteserrados() >= 5;
}

int jachutou(char letra) {
    int achou = 0;

    for(int j = 0; j < chutesDados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
    
}

int main() {
    

    escolhepalavra();
    abertura();

    do {
        desenhaforca();
        chuta();

    } while(!acertou() && !enforcou());

    if(acertou()) {
        printf("\nParabens, voce ganhou!!\n\n");

    } else {
        printf("A palavra secreta era %s\n\n.", palavraSecreta);
        printf("Voce perdeu\n\n");

    }
    adicionapalavra();

}

// \