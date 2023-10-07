#include "s21_matrix.h"
#include <stdio.h>

void s21_print_matrix(matrix_t result) {
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      printf(" %3lf", result.matrix[i][j]);
    }
    printf("\n");
  }
}