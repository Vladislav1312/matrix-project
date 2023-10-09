#include <stdio.h>
#include <stdlib.h>
#include "s21_matrix.h"

int main(){
    int rows = 2; //Количество строк
    int column = 2; //Количество столбцов
    matrix_t res;

    int create = s21_create_matrix(2,2,&res);
    s21_print_matrix(res);
 

    return 0;
}