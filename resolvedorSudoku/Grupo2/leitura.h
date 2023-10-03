/*
    Esta biblioteca possui uma função para realizar a leitura de um
    arquivo.txt, e interpretá-lo em forma de sudoku.
*/

#ifndef _LEITURA_H
#define _LEITURA_H

#include "sudoku.h"

/*
    Esta função, recebe um sudoku.txt e uma matriz como parâmetros.
    Seu objetivo, é "passar" os valores do sudoku.txt para a matriz 
    "matriz".
*/
void LerSudoku (FILE* sudoku, int** matriz);

#endif