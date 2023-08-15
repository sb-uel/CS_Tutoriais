/*
Gerador de Caça Palavras
Projeto Tutorial 2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 15
#define MAX_WORDS 10

void printGridToFile(FILE *file, char grid[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%c ", grid[i][j]);
        }
        fprintf(file, "\n");
    }
}

void fillGridWithRandomLetters(char grid[MAX_SIZE][MAX_SIZE], int size) {
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == ' ') {
                grid[i][j] = letters[rand() % (sizeof(letters) - 1)];
            }
        }
    }
}

int main() {
    int size, numWords;

    printf("Bem-vindo ao Gerador de Caça-Palavras!\n");
    printf("Digite o tamanho do caça-palavras (entre 5 e %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 5 || size > MAX_SIZE) {
        printf("Tamanho inválido. Escolha um valor entre 5 e %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Digite o número de palavras (até %d): ", MAX_WORDS);
    scanf("%d", &numWords);

    if (numWords > MAX_WORDS) {
        printf("Número de palavras excedeu o limite de %d. Redefina o valor.\n", MAX_WORDS);
        return 1;
    }

    char grid[MAX_SIZE][MAX_SIZE];

    // Inicializar a grade com espaços em branco
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = ' ';
        }
    }

    // Ler palavras escolhidas pelo usuário e colocá-las na grade
    for (int w = 0; w < numWords; w++) {
        char word[50];
        printf("Digite a palavra %d: ", w + 1);
        scanf("%s", word);

        int len = strlen(word);

        if (len > size) {
            printf("A palavra é muito longa para caber na grade. Tente novamente.\n");
            w--;
            continue;
        }

        int row, col, dir;
        do {
            row = rand() % size;
            col = rand() % size;
            dir = rand() % 8;  // 8 direções possíveis
        } while (dir == 0 && row - len < 0 || dir == 1 && row + len >= size || dir == 2 && col + len >= size ||
                 dir == 3 && col - len < 0 || dir == 4 && row - len < 0 && col + len >= size ||
                 dir == 5 && row + len >= size && col + len >= size || dir == 6 && row + len >= size && col - len < 0 ||
                 dir == 7 && row - len < 0 && col - len < 0);

        int valid = 1;
        for (int i = 0; i < len; i++) {
            int newRow = row + (dir == 0 || dir == 4 || dir == 5 ? -i : dir == 1 || dir == 6 || dir == 7 ? i : 0);
            int newCol = col + (dir == 2 || dir == 5 || dir == 6 ? i : dir == 3 || dir == 4 || dir == 7 ? -i : 0);

            if (grid[newRow][newCol] != ' ' && grid[newRow][newCol] != word[i]) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            for (int i = 0; i < len; i++) {
                int newRow = row + (dir == 0 || dir == 4 || dir == 5 ? -i : dir == 1 || dir == 6 || dir == 7 ? i : 0);
                int newCol = col + (dir == 2 || dir == 5 || dir == 6 ? i : dir == 3 || dir == 4 || dir == 7 ? -i : 0);
                grid[newRow][newCol] = word[i];
            }
        } else {
            printf("Não foi possível encaixar a palavra na grade. Tente novamente.\n");
            w--;
        }
    }

    fillGridWithRandomLetters(grid, size);

    FILE *file = fopen("cacapalavras.txt", "w");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo.\n");
        return 1;
    }

    printf("\nCaça-Palavras Gerado e Armazenado no arquivo cacapalavras.txt:\n");
    printGridToFile(file, grid, size);

    fclose(file);

    return 0;
}
