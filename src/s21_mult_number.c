#include <stdlib.h>

#include "s21_matrix.h"

//Результирующий код:
// 0 - OK;
// 1 - Ошибка, некорректная матрица;
// 2 - Ошибка вычисления(несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и тд.);

// Умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = 0;  //Ошибка компиляции - OK

  if (A->matrix == NULL) {  //Матрица == NULL
    flag = 1;
    result->matrix = NULL;
  }
  if (A->rows <= 0 || A->columns <= 0) {  //Матрица имеет неправильный размер
    flag = 1;
    result->matrix = NULL;
  }

  if (!flag) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return flag;
}