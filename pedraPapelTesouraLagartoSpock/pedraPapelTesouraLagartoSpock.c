/*
Pedra Papel Tesoura Lagarto Spock
Projeto Tutorial 2023
*/
#include <stdio.h>

int main(){
    printf("\n***************\n");
    printf(" Pedra Papel Tesoura Lagarto Spock\n");

    int jogador1 = 0;
    int jogador2 = 0;
    int jogada1, jogada2;

    while(jogador1 < 5 && jogador2 < 5){
        printf("\n***************\n");
        printf("PONTOS:\n");
        printf("[Jogador 1] %d x %d [Jogador 2]\n", jogador1, jogador2);
        printf("\n***************\n");
        printf("Vez do JOGADOR 1\n");
        printf("Escolha a jogada:\n");
        printf("[1] Pedra\n[2] Papel\n[3] Tesoura\n[4] Lagarto\n[5] Spock \n");
        printf("***************\n");

        printf("Jogada: ");
        scanf("%d", &jogada1);

        printf("\n***************\n");
        printf("Vez do JOGADOR 2\n");
        printf("Jogada: ");
        scanf("%d", &jogada2);

        if(jogada1 == 1){
            if(jogada2 == 2 || jogada2 == 5){
                jogador2++;
            }else if(jogada2 == 3 || jogada2 == 4){
                jogador1++;
            }
        }else if(jogada1 == 2){
            if(jogada2 == 3 || jogada2 == 4){
                jogador2++;
            }else if(jogada2 == 1 || jogada2 == 5){
                jogador1++;
            }
        }else if(jogada1 == 3){
            if(jogada2 == 1 || jogada2 == 5){
                jogador2++;
            }else if(jogada2 == 2 || jogada2 == 4){
                jogador1++;
            }
        }else if(jogada1 == 4){
            if(jogada2 == 1 || jogada2 == 3){
                jogador2++;
            }else if(jogada2 == 2 || jogada2 == 5){
                jogador1++;
            }
        }else if(jogada1 == 5){
            if(jogada2 == 2 || jogada2 == 4){
                jogador2++;
            }else if(jogada2 == 1 || jogada2 == 3){
                jogador1++;
            }
        }
    }

    printf("\n***************\n");
    
    if(jogador1 == 5){
        printf("JOGADOR 1 VENCEU!\n");
    }else{
        printf("JOGADOR 2 VENCEU!\n");
    }

    printf("Obrigada por jogar! :)\n");
    
    return 0;
}
