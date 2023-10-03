/*
Cifra de César - resultado esperado
Projeto Tutorial 2023
*/
#include <stdio.h>
#include <string.h>

void criptografar(char *mensagem, int codigo){
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
}

void desencriptografar(char *mensagem, int codigo){
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
}

int main(){
    printf("\n***************\n");
    printf(" Cifra de César\n");

    int opcao, codigo, tipoInput;
    char mensagem[200], nomeArquivo[50];
    FILE *arquivo, *input;

    printf("\n***************\n");
    printf("[1]Criptografar [2]Descriptografar \n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    printf("***************\n");
    printf("Escolha o código para a ação (de 1 a 25): ");
    scanf("%d", &codigo);

    if(codigo <= 0 || codigo >= 26){
        codigo = 1;
    }

    printf("\n***************\n");
    printf("[3]Ler uma frase [4]Ler um arquivo (.txt)\n");
    printf("Escolha o tipo de input: ");
    scanf("%d", &tipoInput);

    if(tipoInput == 4){
        printf("\n***************\n");
        printf("Digite o nome do arquivo: ");
        scanf(" %[^\n]", nomeArquivo);

        input = fopen(nomeArquivo, "r");

        if(input == NULL){
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        if(opcao == 2){
            arquivo = fopen("mensagemDescriptografada.txt", "w");

            while(fgets(mensagem, 200, input) != NULL){
                desencriptografar(mensagem, codigo);
                fprintf(arquivo, "%s", mensagem);
            }

        }else{
            arquivo = fopen("mensagemCriptografada.txt", "w");

            while(fgets(mensagem, 200, input) != NULL){
                criptografar(mensagem, codigo);
                fprintf(arquivo, "%s", mensagem);
            }
        }

    }else{
        printf("\n***************\n");
        printf("Digite a frase: ");
        scanf(" %[^\n]", mensagem);

        if(opcao == 2){
            arquivo = fopen("mensagemDescriptografada.txt", "w");
            desencriptografar(mensagem, codigo);
        }else{
            arquivo = fopen("mensagemCriptografada.txt", "w");
            criptografar(mensagem, codigo);
        }

        fprintf(arquivo, "%s\n", mensagem);
    }

    fclose(arquivo);

    printf("Mensagem salva no arquivo!\n");
    printf("***************\n");
    printf("Obrigada por utilizar! :)\n");

    return 0;
}