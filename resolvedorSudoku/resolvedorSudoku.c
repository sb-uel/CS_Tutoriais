/*
Resolvedor de Sudoku - resultado esperado
Projeto Tutorial 2023
*/
#include <stdio.h>
#define N 9

int grid[N][N];

int isSafe(int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return 0;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= N; num++) {
                    if (isSafe(row, col, num)) {
                        grid[row][col] = num;

                        if (solveSudoku()) {
                            return 1;
                        }

                        grid[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

void printGrid(FILE *outputFile) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            fprintf(outputFile, "%2d ", grid[row][col]);
        }
        fprintf(outputFile, "\n");
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            fscanf(inputFile, "%d", &grid[row][col]);
        }
    }
    fclose(inputFile);

    if (solveSudoku()) {
        FILE *outputFile = fopen("output.txt", "w");
        if (outputFile == NULL) {
            printf("Não foi possível criar o arquivo de saída.\n");
            return 1;
        }

        printGrid(outputFile);
        fclose(outputFile);

        printf("Sudoku resolvido e salvo em output.txt\n");
    } else {
        printf("Não foi possível resolver o Sudoku.\n");
    }

    return 0;
}
