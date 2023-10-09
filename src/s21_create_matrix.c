#include "s21_matrix.h"
#include <stdlib.h>

//Результирующий код:
//0 - OK;
//1 - Ошибка, некорректная матрица;
//2 - Ошибка вычисления(несовпадающие размеры матриц; матрица, для которой нельзя провести вычисления и тд.);

int s21_create_matrix(int rows, int columns, matrix_t *result){
    int flag = 0; //Ошибка компиляции - OK

    if(rows > 0 && columns > 0){
        result -> matrix = (double**)calloc(rows, (sizeof(double*))); //Выделение памяти на кол-во указателей строк
        result -> rows = rows;
        result -> columns = columns;
        for(int i = 0; i < rows; i++){
            result -> matrix[i] = (double*)calloc(columns, sizeof(double)); //Выделение памяти на кол-во столбцов
            for(int y = 0; y < columns; y++){
                result -> matrix[i][y] = 2;
            }
        }
    }else{
        flag = 1; //Ошибка компиляции - Некорректная матрица;
        free(result -> matrix);
    }
    return flag;
}