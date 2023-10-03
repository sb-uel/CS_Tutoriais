#include "sudoku.h"

void ResolveSudoku (int** sudoku) {

    TestaValores (0, 0, sudoku);
}

void TestaValores (int linha, int coluna, int** sudoku) {

    if (linha == 9) return; // Caso termine o sudoku.

    for (int valor = 1; valor <= 9; valor++) { // Percorre os valores a serem testados
        if (ConfereValor(linha, coluna, valor, sudoku)) {
            int aux = sudoku[linha][coluna];
            sudoku[linha][coluna] = valor;      

            if (coluna == 8) TestaValores(linha + 1, 0, sudoku); // Caso tenha chego ao fim da linha, pula para a proxima.
            else TestaValores(linha, coluna + 1, sudoku); // Vai para a proxima casa da linha

            if (!ConfereSudoku(sudoku)) sudoku[linha][coluna] = aux;
        }
    }
}

bool ConfereValor (int linha, int coluna, int valor, int** sudoku) {

    if (sudoku[linha][coluna] == valor) return true;
    if (sudoku[linha][coluna] != 0) return false;

    for (int col = 0; col < 9; col++) if (sudoku[linha][col] == valor) return false; // Confere se o valor a ser testado, existe na mesma linha.
    for (int lin = 0; lin < 9; lin++) if (sudoku[lin][coluna] == valor) return false; // Confere se o valor a ser testado, existe na mesma coluna.

    int linhaQ = linha/3; // Representa a linha de um dos quadrantes 3x3.
    int colunaQ = coluna/3; // Representa a coluna de um dos quadrantes 3x3.

    // Confere se o valor testado, existe no mesmo quadrante 3x3.
    for (int lin = linhaQ * 3; lin < (linhaQ + 1) * 3; lin++) {
        for (int col = colunaQ * 3; col < (colunaQ + 1) * 3; col++) {
            if (sudoku[lin][col] == valor) return false;
        }
    }

    return true;
}

bool ConfereSudoku (int** sudoku) {

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (*(*(sudoku + j) + i) == 0) return false;
        }
    }

    return true;
}

void EscreveSudoku (int** sudoku) {

    FILE* arq = fopen("saida.txt", "w");

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fprintf (arq, "%d ", sudoku[i][j]); // Escreve as linhas do sudoku.
            if ((j+1) % 3 == 0) fprintf (arq, " "); // Escreve um espaçamento entre os espaços 3x3.
        }
        fprintf (arq, "\n"); 
        if ((i+1) % 3 == 0) fprintf (arq, "\n");
    }

    fclose(arq);
}