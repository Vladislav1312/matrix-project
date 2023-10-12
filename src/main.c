#include <stdio.h>
#include <stdlib.h>
#include "s21_matrix.h"

int main(){
    matrix_t A;
    matrix_t B;
    matrix_t res;

    int create_A = s21_create_matrix(3,3,&A);
    s21_add_value_matrix(&A);

    printf("\nВывод матрицы A:\n\n");
    s21_print_matrix(&A);
    printf("\nОшибка CREATE_MATRIX - %d", create_A);

    
    int create_B = s21_create_matrix(2,2,&B);
    s21_add_value_matrix(&B);

    printf("\n\nВывод матрицы B:\n\n");
    s21_print_matrix(&B);
    printf("\nОшибка CREATE_MATRIX - %d\n", create_B);
    
    
    
    int create_RES = s21_create_matrix(2,2, &res);
    printf("\n%d\n", create_RES);


    // int sum = s21_sum_matrix(&A, &B, &res);
    // printf("\n\nВывод матрицы RES(sum):\n\n");
    // s21_print_matrix(&res);
    // printf("\nОшибка SUM_MATRIX - %d\n", sum);

    // int sub = s21_sub_matrix(&A, &B, &res);
    // printf("\n\nВывод матрицы RES(sub):\n\n");
    // s21_print_matrix(&res);
    // printf("\nОшибка SUB_MATRIX - %d\n", sub);

    // double num = 2.3;
    // int mult_number = s21_mult_number(&A, num, &res);
    // printf("\n\nВывод матрицы RES(mult_number):\n\n");
    // s21_print_matrix(&res);
    // printf("\nОшибка MULT_NUMBER - %d\n", mult_number);

    // int mult = s21_mult_matrix(&A, &B, &res);
    // printf("\n\nВывод матрицы RES(mult):\n\n");
    // s21_print_matrix(&res);
    // printf("\nОшибка MULT_MATRIX - %d\n", mult);

    // int transpose = s21_transpose(&A, &res);
    // printf("\n\nВывод матрицы RES(transpose):\n\n");
    // s21_print_matrix(&res);
    // printf("\nОшибка TRANSPOSE_MATRIX - %d\n", transpose);

    int calc_complements = s21_calc_complements(&A, &res);
    printf("\n\nВывод матрицы RES(calc_complements):\n\n");
    s21_print_matrix(&res);
    printf("\nОшибка CALC_COMPLEMENTS - %d\n", calc_complements);

    

    // printf("\n________Сравнение двух матриц________\n");
    // printf("Вывод %d\n", s21_eq_matrix(&A, &B));

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&res);
 
    return 0;
}