#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void readMatrix(int mat[9][9], const char *file_name)
{
    FILE *file = fopen(file_name,"r");

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            fscanf(file,"%d",&mat[i][j]);
    }
}

void printSudoku(int mat[9][9])
{
    printf("\n\t\t\t\t\t%c",201);

    for (int i = 0; i < 33; i++)
    {
        if (i == 11 || i == 22)
            printf("%c",203);
        printf("%c",205);
    }
    printf("%c\n",187);
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 0)
                printf("\t\t\t\t\t%c",186);
            
            printf(" %d ",mat[i][j]);

            if (j == 2 || j == 5 || j == 8)
                printf("%c",186);
            else
                printf("%c",179);
        }
        if (i!= 8){
            if (i != 2 && i != 5){
                for (int k = 0; k < 36; k++)
                {
                    if (k == 0)
                        printf("\n\t\t\t\t\t%c",186);
                    else if (k == 12 || k == 24)
                        printf("%c",186);
                    else if (k % 4 == 0)
                        printf("%c",197);
                    else
                        printf("%c",196);
                }
                printf("%c\n",186);
            }
            else{
                printf("\n\t\t\t\t\t%c",204);
                for (int k = 0; k < 35; k++){
                    if (k == 11 || k == 23)
                    {
                        printf("%c",206);
                    }
                    else{
                        printf("%c",205);
                    }
                }
                printf("%c\n",185);
            }
        }    
    }
    printf("\n\t\t\t\t\t%c",200);
    for (int i = 0; i < 33; i++)
    {
        if (i == 11 || i == 22)
            printf("%c",202);
        printf("%c",205);
    }
    printf("%c\n\n\n\n\n\n\n",188);
}

bool scanRow(int mat[9][9], int i, int num)
{
    for (int j = 0; j < 9; j++)
    {
        if (mat[i][j] == num)
            return false;
    }

    return true;
}

bool scanColumn(int mat[9][9], int j, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (mat[i][j] == num)
            return false;
    }

    return true;
}

bool scanSquare(int mat[9][9], int x, int y, int num)
{
    if (x < 3)
        x = 0;
    else if (x < 6)
        x = 3;
    else
        x = 6;

    if (y < 3)
        y = 0;
    else if (y < 6)
        y = 3;
    else
        y = 6;

    for (int i = x; i < x+3; i++)
    {
        for (int j = y; j < y+3; j++)
            if (mat[i][j] == num)
                return false;
    }

    return true;
}

bool validPosition(int mat[9][9], int x, int y, int num) //Chama as funções de linha, coluna e quadrante
{
    return scanRow(mat,x,num) && scanColumn(mat,y,num) && scanSquare(mat,x,y,num);
}

bool findEmptyPosition(int mat[9][9], int *row, int *column) //Procura posição vazia na matriz caso houver
{
    for (*row = 0; *row < 9; (*row)++)
    {
        for (*column = 0; *column < 9; (*column)++)
        {
            if (mat[*row][*column] == 0)
                return true;
        }
    }

    return false;
}

bool sudokuSolver(int mat[9][9])
{
    int row, column;

    if (!findEmptyPosition(mat,&row,&column))
        return true; //Todas posições completadas

    for (int num = 1; num <= 9; num++) //Testa valores de 1 até 9
    {
        if (validPosition(mat,row,column,num)) //Verifica se o valor é válido na posição
        {
            mat[row][column] = num;

            if (sudokuSolver(mat)) //Recursão
                return true;

            mat[row][column] = 0;
        }
    }

    return false;
}

int main()
{
    int mat[9][9];

    char fileName[50] = "sudokuMatrix.txt";
    readMatrix(mat,fileName);

    if (sudokuSolver(mat))
    {
        printf("\n\n\n\n\n\t\t\t\t\t\t  SUDOKU RESOLVIDO\n");
        printSudoku(mat);
    }
    else
    {
        printf("\n\n\n\n\n\t\t\t\t\t\t  SUDOKU SEM SOLUCAO\n");
        printSudoku(mat);
    }

    return 0;
}