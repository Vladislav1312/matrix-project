#include "s21_matrix.h"
#include <stdlib.h>
#include <stdio.h>

//SUCCESS 1
//FAILURE 0

// Сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B){
    int flag = 1; //Матрицы равны

    if(A -> matrix == NULL || B -> matrix == NULL){ //Матрицы == NULL
        flag = 0;
    }
    if((A -> rows <= 0 || A-> columns <= 0) || (B -> rows <= 0 || B -> columns <= 0)){ //Матрицы имеют неправильный размер
        flag = 0;  
    }
    if((A -> rows != B -> rows) || (A-> columns != B -> columns)){ //Размер матриц не совпадает
        flag = 0;
    } 
    
    if(flag){
        for(int i = 0; i < A -> rows; i++){
            for(int j = 0; j < A -> columns; j++){
                if(A -> matrix[i][j] != B -> matrix[i][j]){
                    flag = 0;
                }
            }
        }
    }
    
    return flag;
}