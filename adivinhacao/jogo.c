#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    // Imprime o cabecalho do jogo
    printf("*************************************\n");
    printf("* Bem vindo ao jogo de adivinhacao *\n");
    printf("*************************************\n");

    int segundos = time(0);
    srand(segundos);
    int numeroGrande = rand();

    int numeroSecreto = numeroGrande % 100;
    int chute;
    int tentativas = 1; 
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nivel de dificuldade?\n");
    printf("(1) Facil, (2) Medio, (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numeroDeTentativas;

    switch (nivel) {
        case 1:
            numeroDeTentativas = 15;
            printf("Nivel Facil escolhido, voce tem %d tentativas! Vamos comecar!!\n", numeroDeTentativas);
            break;
        case 2:
            numeroDeTentativas = 10;
            printf("Nivel Medio escolhido, voce tem %d tentativas! Vamos comecar!!\n", numeroDeTentativas);
            break;
        default:
            numeroDeTentativas = 5;
            printf("Nivel Dificil escolhido, voce tem %d tentativas! Vamos comecar!!\n", numeroDeTentativas);
            break;
    }
    
    for (int i = 1; i <= numeroDeTentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual e o seu chute? ");

        printf("\n");
        scanf("%d", &chute);
        printf("Seu numero foi este?\n");
        printf("%d", chute);
        printf("\n");

         if (chute < 0) {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        
        if (acertou) {
            break;
        }   
        else if (maior) {
            printf("Seu chute foi maior do que o numero secreto. Tente de novo\n");
        }
        else {
            printf("Seu chute foi menor do que o numero secreto\n");
        }
        tentativas ++;

        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
        pontos = pontos - pontosPerdidos;
    }

    printf("Fim de jogo!\n");

     if (acertou) {
        printf("Voce ganhou!\n");
        printf("Voce acertou em %d tentativas!!\n", tentativas);
        printf("Total de pontos %.2f\n", pontos);
    }
    else {
        printf("Voce perdeu! Tente de novo!\n");
    }
}    