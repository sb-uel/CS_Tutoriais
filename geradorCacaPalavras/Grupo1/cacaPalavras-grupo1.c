#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void ImprimirMatriz(char **matriz, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

void SalvarMatriz(char **matriz, int linhas, int colunas){ //salva a matriz resultante, o tabuleiro, em um arquivo txt
    FILE *arquivo;
    arquivo = fopen("TABULEIRO.txt", "w");
    if (arquivo == NULL) {
        printf("Nao foi possivel criar o arquivo\n");
        return ;
    }
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            fprintf(arquivo, "%c ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    printf("Salvo em 'TABULEIRO.txt'.\n");
}

void PreencheMatriz(char **matriz, int linhas, int colunas){
    srand(time(NULL));
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = 'A' + rand() % 26; // preenche o restante da matriz com letras aleatórias maiúsculas de A a Z
        }
    }
}

bool Verificacao(int linhas, int colunas, int x, int y, int len, int passoX, int passoY, int **matrizAux){
    for(int i = 0; i < len; i++){
        if(x < 0 || x >= linhas || y < 0 || y >= colunas || matrizAux[x][y] == 1){
            return false;
        }
        x += passoX;
        y += passoY;
    }
    return true;
    //essa função verifica se a palavra pode continuar a ser inserida na posição do próxima letra.
    //se puder, retorna a um valor valido, se não, retorna a um valor inválido
}

void InserirPalavra(char **matriz, int **matrizAux, char palavra[], int len, int x, int y, int passoX, int passoY){
    for (int i = 0; i < len; i++){
        matriz[x][y] = palavra[i]; //preenche a matriz principal com a palavra
        matrizAux[x][y] = 1; //também marca a matriz auxiliar com 1s, para facilitar a verificacao
        x += passoX;
        y += passoY;
    }
}

void PosicaoDasPalavras(char **matriz, int **matrizAux, int linhas, int colunas, char palavras[][20], int numPalavras){
    srand(time(NULL));
    for (int k = 0; k < numPalavras; k++){
        char palavra[20];
        strcpy(palavra, palavras[k]);
        int len = strlen(palavra);

        int x, y, passoX, passoY;
        int tentativas = 0;
        int encaixa = 0;

        while (!encaixa && tentativas < linhas * colunas){
            /*essa repetição procurará uma posição válida até encontrar, se não encontrar (variavel 'encaixa'
            valer 0 e as tentaivas excederem a área da matriz), não é possível encontrar uma posição válida*/
            int direcao = rand() % 7; // 0: horizontal, 1: vertical, 2: diagonal, 3: backwards

            x = rand() % linhas;  //escolhe uma coordenada aleatória para ->
            y = rand() % colunas; //começar a inserção da palavra no tabuleiro

            switch (direcao){
                case 0: //horizontal, anda para a direita
                    passoX = 1;
                    passoY = 0;
                break;
                case 1: //vertical, anda para cima
                    passoX = 0;
                    passoY = 1;
                break;
                case 2: //diagonal 1, para direita e para cima
                    passoX = 1;
                    passoY = 1;
                break;
                case 3: //diagonal 2, para direita e para baixo
                    passoX = 1;
                    passoY = -1;
                break;
                case 4: //diagonal 3, anda para e esquerda e para cima
                    passoX = -1;
                    passoY = 1;
                break;
                case 5: //diagonal 4, anda para a esquerda e para baixo
                    passoX = -1;
                    passoY = -1;
                break;
                case 6: //backwars, anda para a esquerda
                    passoX = -1;
                    passoY = 0;
                break;
            }
            if (Verificacao(linhas, colunas, x, y, len, passoX, passoY, matrizAux)) {
                InserirPalavra(matriz, matrizAux, palavra, len, x, y, passoX, passoY);
                encaixa = 1;
            }
            tentativas++;
        }
        if (!encaixa){
            printf("Nao foi possivel encaixar a palavra %s no tabuleiro\n", palavra); //se não é possível encaixar, o código exibe uma mensagem de erro
            exit(1);
        }
    }
}

int main()
{
    int linhas, colunas, numPalavras;
    printf("---------------------------GERADOR DE CACA PALAVRAS---------------------------\n");
    printf("--Recomendacao: palavras com letras maiusculas e com maximo de 20 caracteres--\n\n");

    printf("Informe o numero de linhas do tabuleiro: ");
    scanf("%d", &linhas);
    printf("Informe o numero de colunas do tabuleiro: ");
    scanf("%d", &colunas);

    char **matriz = (char **)malloc(linhas * sizeof(char *)); //MATRIZ CHAR PRINCIPAL, TABULEIRO
    for (int i = 0; i < linhas; i++){
        matriz[i] = (char *)malloc(colunas * sizeof(char));
    }

    int **matrizAux = (int **)malloc(linhas * sizeof(int *)); //MATRIZ INT AUXILIAR
    for (int i = 0; i < linhas; i++){
        matrizAux[i] = (int *)malloc(colunas * sizeof(int));
        for (int j = 0; j < colunas; j++){
            matrizAux[i][j] = 0; //inicializar todas as posições da matriz auxiliar com 0
        }
    }

    printf("Quantas palavras deseja inserir? ");
    scanf("%d", &numPalavras);
    char palavras[numPalavras][20]; //matriz com as palavras inseridas, tamanho max. de 20

    for (int i = 0; i < numPalavras; i++){
        printf("Insira a palavra %d: ", i + 1);
        scanf("%s", palavras[i]);
        if ((int)strlen(palavras[i]) > linhas || (int)strlen(palavras[i]) > colunas){
            //se o tamanho da palavra for maior que o numero de linhas e colunas, é impossível coloca-las na matriz
            printf("A palavra %s excede o tamanho do tabuleiro\n", palavras[i]);
            return 1;
        }
    }

    PreencheMatriz(matriz, linhas, colunas);
    PosicaoDasPalavras(matriz, matrizAux, linhas, colunas, palavras, numPalavras);

    printf("\nTabuleiro gerado:\n");
    ImprimirMatriz(matriz, linhas, colunas);

    SalvarMatriz(matriz, linhas, colunas);

    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}