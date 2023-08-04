/*
Calculadora Simples 
Projeto Tutorial 2023
*/
#include <stdio.h>

int main(){
    printf("\n***************\n");
    printf(" Calculadora\n");

    int operacao = -1;
    int num1, num2;

    while(operacao != 0){
        printf("\n***************\n");
        printf("Escolha a operação:\n");
        printf("[1] +  [2] -  [3] x  [4] /\n");
        printf("[0] Sair\n");
        printf("***************\n");

        printf("Operação: ");
        scanf("%d", &operacao);

        if(operacao == 0){
            break;
        }

        printf("Digite um número: ");
        scanf("%d", &num1);
        printf("Agora outro: ");
        scanf("%d", &num2);
        printf("\n");

        if(operacao == 1){
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
        }else if(operacao == 2){
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
        }else if(operacao == 3){
            printf("%d x %d = %d\n", num1, num2, num1 * num2);
        }else if(operacao == 4){
            printf("%d / %d = %.3f\n", num1, num2, (float) num1 / num2);
        }        
    }
    printf("\n***************\n");
    printf("Obrigada por utilizar! :)\n");
    
    return 0;
}
