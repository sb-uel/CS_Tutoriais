/*
    Este programa, tem como intuito, resolver um sudoku 9x9 incompleto,
    o qual, será dado como entrada em um arquivo .txt. Em seguida, retornará 
    este e irá escrever a resolução do sudoku em outro arquivo .txt.

    O programa será feito na linguagem C.

    Caso não saiba como funciona um sudoku ou como resolvê-lo, acesse
    o site abaixo.
    https://sudoku.com/pt/regras-do-sudoku/

    A estratégia utilizada foi a de BackTracking, para saber mais, vá para:
    http://www3.decom.ufop.br/toffolo/site_media/uploads/2011-1/bcc402/slides/10._backtracking.pdf
*/

#include "headers.h"

int main() {

    // Alocando matriz, para armazenar o sudoku, dinamicamente.
    int** Sudoku = malloc(9 * sizeof(int*));
    for (int i=0; i<9; i++) Sudoku[i] = malloc(9 * sizeof(int));

    FILE* arq = fopen("sudoku.txt", "r");

    LerSudoku(arq, Sudoku); // Passando o sudoku para a matriz.

    ResolveSudoku(Sudoku); // Resolvendo o sudoku.

    // Conferindo se o sudoku de fato foi resolvido.
    if (ConfereSudoku(Sudoku)) EscreveSudoku(Sudoku);
    else printf ("\nSudoku não possui solução\n\n");

    return 0;

}