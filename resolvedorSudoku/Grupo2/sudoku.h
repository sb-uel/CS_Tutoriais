/*
    Esta biblioteca, inclui funções para a resolução de um sudoku 9x9,
    além de funções auxiliares, para conferir se está completo e para 
    escreve o sudoku.
*/

#ifndef _SUDOKU_H
#define _SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*
    Função a qual resolver um sudoku. Ela recebe uma matriz int,
    a qual, "armazena" o sudoku a ser resolvido.
*/
void ResolveSudoku (int** sudoku);

/*
    Função auxiliar, a qual vai testar os valores possíveis para
    um espaço do sudoku.
*/
void TestaValores (int linha, int coluna, int** sudoku);

/*
    Função booleana, a qual conferese se uma certo valor int "valor"
    1 <= valor <= 9, é um possível valor a ser testado na linha "linha"
    e coluna "coluna" do sudoku "sudoku". 

    Retorna true caso o elemento possa ser testado, e false caso contrário.
*/
bool ConfereValor (int linha, int coluna, int valor, int** sudoku);

/*
    Função a qual confere se o sudoku "sudoku" está completo.
    
    Retorna true caso esteja, e false caso contrário.
*/
bool ConfereSudoku (int** sudoku);

/*
    Função a qual escreve no terminal, o Sudoku "sudoku".
*/
void EscreveSudoku (int** sudoku);

#endif