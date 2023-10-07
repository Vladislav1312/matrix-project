#include <stdio.h>
#include <stdlib.h>
#include "s21_matrix.h"

int main(){
    int rows = 2;
    int column = 2;
    matrix_t result;

    s21_print_matrix(result);

    int result_return = s21_create_matrix(2, 3, &result);
    printf("Result function - %d\n", result_return);

    return 0;
}