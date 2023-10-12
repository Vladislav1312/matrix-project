#include "s21_matrix.h"
#include <stdlib.h>

//Результирующий код:
//0 - OK;
//1 - Ошибка, некорректная матрица;
//2 - Ошибка вычисления(несовпадающие размеры матриц; матрица, для которой нельзя провести вычисления и тд.);

//Минор и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result){
    int flag = 0; //Ошибка компиляции - OK

    if(A -> matrix == NULL){ //Матрица == NULL
        flag = 1;
    }
    if(A -> rows <= 0 || A-> columns <= 0){ //Матрица имеют неправильный размер
        flag = 1;  
    }

    matrix_t minor;
    int rows_minor = (A -> rows) - 1;
    int columns_minor = (A -> columns) - 1;
    s21_create_matrix(rows_minor, columns_minor, &minor);

    

    for(int i = 0; i < result -> rows; i++){
        for(int j = 0; j < result -> columns; j++){
            result -> matrix[i][j] = 0;
        }
    }
    return flag;
}