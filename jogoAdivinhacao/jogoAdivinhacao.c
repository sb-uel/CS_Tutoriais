/*
Jogo da Adivinhação
Projeto Tutorial 2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
    int acertou = 0;
    int nivel, chute, chutesRestantes;

    printf("\n***************\n");
    printf(" Jogo da Adivinhação\n");
    printf("\n[1]Fácil [2]Médio [3]Difícil\n");
    printf("Escolha o nível de dificuldade: ");
    scanf("%d", &nivel);

    if(nivel == 1){
        chutesRestantes = 10;
    }else if(nivel == 2){
        chutesRestantes = 7;
    }else{
        chutesRestantes = 3;
    }

    srand(time(0));
    int numeroSecreto = rand() % 101;
    
    printf("\n***************");

    while(chutesRestantes > 0 && !acertou){
        printf("\nEscolha um número entre 0 e 100.\n");
        printf("Chances restantes: %d\n", chutesRestantes);
        printf("Faça seu chute: ");
        scanf("%d", &chute);

        if(chute > numeroSecreto){
            printf("Muito ALTO!\n");
        }else if(chute < numeroSecreto){
            printf("Muito BAIXO!\n");
        }else{
            printf("Boa!\n");
            acertou = 1;
        }

        chutesRestantes--;
    }

    printf("\nO número escolhido foi %d.\n", numeroSecreto);

    if(acertou){
        printf("Parabéns! Você acertou o número escolhido.\n");
    }else{
        printf("Que pena, tente novamente!\n");
    }

    printf("Obrigada por jogar! :)\n");

    return 0;
}
