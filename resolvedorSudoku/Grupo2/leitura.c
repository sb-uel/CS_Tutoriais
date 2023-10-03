#include "leitura.h"

void LerSudoku (FILE* sudoku, int** matriz) {

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (fscanf(sudoku, "%d", &matriz[i][j]) != 1) return; // Lê cada elemento do sudoku e "transforma em int".
        }
    }
}