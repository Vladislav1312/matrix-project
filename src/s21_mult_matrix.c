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
        flag = 1;  
    }
    if((A -> rows != B -> rows) || (A-> columns != B -> columns)){ //Размер матриц не совпадает
        flag = 2;
    }
}