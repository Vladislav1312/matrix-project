#include <stdio.h>
#include <stdlib.h>
#include "s21_matrix.h"

int main(){
    int rows = 2; //Количество строк
    int column = 2; //Количество столбцов
    matrix_t A;
    matrix_t B;
    matrix_t res;

    int create_A = s21_create_matrix(2,2,&A);

    printf("\nВывод матрицы A:\n\n");
    s21_print_matrix(&A);
    printf("\nОшибка CREATE_MATRIX - %d", create_A);

    int create_B = s21_create_matrix(2,2,&B);

    printf("\n\nВывод матрицы B:\n\n");
    s21_print_matrix(&B);
    printf("\nОшибка CREATE_MATRIX - %d\n", create_B);
    
    
    printf("\n******Сравнение двух матриц******\n");
    printf("Вывод %d\n", s21_eq_matrix(&A, &B));



    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
 
    return 0;
}