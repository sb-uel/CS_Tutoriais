/*
Campo Minado - resultado esperado
Projeto Tutorial 2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15

int rows, cols;
int mines;
int revealed[MAX_SIZE][MAX_SIZE];
int grid[MAX_SIZE][MAX_SIZE];

void initializeGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
            revealed[i][j] = 0;
        }
    }
}

void placeMines() {
    int placedMines = 0;
    while (placedMines < mines) {
        int randRow = rand() % rows;
        int randCol = rand() % cols;
        if (grid[randRow][randCol] != -1) {
            grid[randRow][randCol] = -1;
            placedMines++;
        }
    }
}

int countAdjacentMines(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == -1) {
                count++;
            }
        }
    }
    return count;
}

void printGrid() {
    printf("  ");
    for (int j = 0; j < cols; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("%d ", i);
        for (int j = 0; j < cols; j++) {
            if (revealed[i][j]) {
                if (grid[i][j] == -1) {
                    printf("* ");
                } else {
                    int adjacentMines = countAdjacentMines(i, j);
                    if (adjacentMines == 0) {
                        printf(". ");
                    } else {
                        printf("%d ", adjacentMines);
                    }
                }
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

void revealCell(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols || revealed[row][col]) {
        return;
    }

    revealed[row][col] = 1;
    if (grid[row][col] == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                revealCell(row + i, col + j);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Bem-vindo ao Campo Minado!\n");
    printf("Digite o número de linhas e colunas (até %d): ", MAX_SIZE);
    scanf("%d %d", &rows, &cols);

    if (rows > MAX_SIZE || cols > MAX_SIZE) {
        printf("Tamanho máximo permitido é %d x %d. Redefina os valores.\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    printf("Digite o número de minas: ");
    scanf("%d", &mines);

    if (mines >= rows * cols) {
        printf("Número de minas deve ser menor que %d x %d. Redefina o valor.\n", rows, cols);
        return 1;
    }

    initializeGrid();
    placeMines();

    int gameOver = 0;

    while (!gameOver) {
        printGrid();

        int row, col;
        printf("Digite a linha e a coluna (separadas por espaço) para revelar uma célula: ");
        scanf("%d %d", &row, &col);

        if (grid[row][col] == -1) {
            printf("Boom! Você revelou uma mina. Fim de jogo!\n");
            gameOver = 1;
        } else {
            revealCell(row, col);
        }
    }

    return 0;
}
