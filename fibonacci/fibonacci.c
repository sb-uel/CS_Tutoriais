/*
Fibonacci
Projeto Tutorial 2023
*/
#include <stdio.h>

int main(){
    printf("\n***************\n");
    printf(" Fibonacci\n");

    int n = 1;

    while(n > 0){
        printf("\n***************\n");
        printf("Digite um número: ");
        
        scanf("%d", &n);

        if(n <= 0){
            break;
        }
        
        printf("O %dº termo da sequência é ", n);
        
        int valor1 = 0;
        int valor2 = 1;

        if(n == 1){
            printf("%d\n", valor1);
        }else if(n == 2){
            printf("%d\n", valor2);
        }else{
            int total;

            for(int i = 0; i < n - 2; i++){
                total = valor1 + valor2;
                valor1 = valor2;
                valor2 = total;
            }

            printf("%d\n", total);
        }
    }
    printf("\n***************\n");
    printf("Obrigada por utilizar! :)\n");
    

    return 0;
}
