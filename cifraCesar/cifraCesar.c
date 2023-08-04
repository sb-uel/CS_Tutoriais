/*
Cifra de César 
Projeto Tutorial 2023
*/
#include <stdio.h>
#include <string.h>

int main(){
    printf("\n***************\n");
    printf(" Cifra de César\n");

    int opcao = 1, codigo;
    char mensagem[100], nomeArquivo[50];
    FILE *arquivo;

    while(opcao != 0){
        printf("\n***************\n");
        printf("[0]Sair [1]Criptografar [2]Descriptografar \n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if(opcao == 0){
            break;
        }

        printf("\n***************\n");
        printf("Digite a frase: ");
        scanf(" %[^\n]", mensagem);

        printf("***************\n");
        printf("Digite o código: ");
        scanf("%d", &codigo);

        if(codigo < 0 || codigo > 26){
            codigo = 1;
        }

        if(opcao == 2){
            for(int i = 0; i <= strlen(mensagem); i++){
                if (mensagem[i] >= 'a' && mensagem[i] <= 'z'){
                    if (mensagem[i] - codigo < 'a'){
                        mensagem[i] = mensagem[i] + 26 - codigo;
                    }else{
                        mensagem[i] -= codigo;
                    }
                }else if(mensagem[i] >= 'A' && mensagem[i] <= 'Z'){
                    if (mensagem[i] - codigo < 'A'){
                        mensagem[i] = mensagem[i] + 26 - codigo;
                    }else{
                        mensagem[i] -= codigo;
                    }
                }
            }
            arquivo = fopen("mensagemDescriptografada.txt", "w");

        }else{
            for(int i = 0; i < strlen(mensagem); i++){
                if (mensagem[i] >= 'a' && mensagem[i] <= 'z'){
                    if (mensagem[i] + codigo > 'z'){
                        mensagem[i] = mensagem[i] - 26 + codigo;
                    }else{
                        mensagem[i] += codigo;
                    }
                }else if(mensagem[i] >= 'A' && mensagem[i] <= 'Z'){
                    if (mensagem[i] + codigo > 'Z'){
                        mensagem[i] = mensagem[i] - 26 + codigo;
                    }else{
                        mensagem[i] += codigo;
                    }
                }
            }
            arquivo = fopen("mensagemCriptografada.txt", "w");

        }

        fprintf(arquivo, "%s\n", mensagem);
        fclose(arquivo);
        printf("Mensagem salva no arquivo!\n");
    }

    printf("\n***************\n");
    printf("Obrigada por utilizar! :)\n");

    return 0;
}