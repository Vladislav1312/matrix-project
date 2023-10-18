#include <stdlib.h>

#include "s21_matrix.h"

//Результирующий код:
// 0 - OK;
// 1 - Ошибка, некорректная матрица;
// 2 - Ошибка вычисления(несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и тд.);

// Транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = 0;  //Ошибка компиляции - OK

  if (A->matrix == NULL) {  //Матрица == NULL
    flag = 1;
    result->matrix = NULL;
  }
  if (A->rows <= 0 || A->columns <= 0) {  //Матрица имеют неправильный размер
    flag = 1;
    result->matrix = NULL;
  }

  if (!flag) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }

  return flag;
}