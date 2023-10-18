#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

//Результирующий код:
// 0 - OK;
// 1 - Ошибка, некорректная матрица;
// 2 - Ошибка вычисления(несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и тд.);

//Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = 0;  //Ошибка компиляции - OK

  if (A->matrix == NULL &&
      (A->rows <= 0 || A->columns <= 0)) {  //Матрица == NULL
    flag = 1;
    result->matrix = NULL;
  } else if (A->rows != A->columns) {
    flag = 2;
    result->matrix = NULL;
  }

  if (!flag) {
    matrix_t matrix_1;  //Матрица алгебраических дополнений
    matrix_t matrix_2;  //Матрица после траспонирования

    s21_create_matrix(A->rows, A->columns, result);

    double deter = 0;
    int deter_fun = s21_determinant(A, &deter);  //Определитель матрицы А
    if (deter_fun == 0) {
      if (deter == 0) {
        flag = 2;  //Ошибка вычисления : нельзя провести вычисления
      }

      if (A->rows == 1) {
        result->matrix[0][0] = 1 / A->matrix[0][0];
      } else {
        s21_calc_complements(A, &matrix_1);
        s21_transpose(&matrix_1, &matrix_2);

        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = matrix_2.matrix[i][j] / deter;
          }
        }
        s21_remove_matrix(&matrix_1);
        s21_remove_matrix(&matrix_2);
      }
    }
  }

  return flag;
}