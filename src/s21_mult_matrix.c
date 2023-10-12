#include "s21_matrix.h"
#include <stdlib.h>

//Результирующий код:
//0 - OK;
//1 - Ошибка, некорректная матрица;
//2 - Ошибка вычисления(несовпадающие размеры матриц; матрица, для которой нельзя провести вычисления и тд.);

//Умножение матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int flag = 0; //Ошибка компиляции - OK

    if(A -> matrix == NULL || B -> matrix == NULL){ //Матрицы == NULL
        flag = 1;
    }
    if((A -> rows <= 0 || A-> columns <= 0) || (B -> rows <= 0 || B -> columns <= 0) || (A -> columns != B -> rows)){ //Матрицы имеют неправильный размер
        flag = 2;  
    }

    if(!flag){
        s21_create_matrix(A -> rows, B -> columns, result);
        for(int i = 0; i < result -> rows; i++){
            for(int j = 0; j < result -> columns; j++){
                result -> matrix[i][j] = 0;
                for(int x = 0; x < A -> columns; x++){
                    result -> matrix[i][j] += A -> matrix[i][x] * B -> matrix[x][j];
                }
            }
        }
    }
    return flag;
}