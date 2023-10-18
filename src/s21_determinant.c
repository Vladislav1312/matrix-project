#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

//Результирующий код:
// 0 - OK;
// 1 - Ошибка, некорректная матрица;
// 2 - Ошибка вычисления(несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и тд.);

//Определитель матрицы
int s21_determinant(matrix_t *A, double *result) {
  int flag = 0;  //Ошибка компиляции - OK

  if (A->matrix == NULL &&
      (A->rows <= 0 || A->columns <= 0)) {  //Матрица == NULL
    flag = 1;
  } else if (A->rows != A->columns) {
    flag = 2;
  }

  if (!flag) {
    *result = s21_get_determinant_minor(A, A->rows);
  }

  return flag;
}

//Функция для рекурсии миноров n порядка
double s21_get_determinant_minor(matrix_t *A, int n) {
  double result = 0;
  if (n == 1) {  //Размер матрицы 1*1

    result = A->matrix[0][0];

  } else if (n == 2) {  //Размер матрицы 2*2

    result = ((A->matrix[0][0] * A->matrix[1][1]) -
              (A->matrix[0][1] * A->matrix[1][0]));

  } else if (n >= 3) {  //Размер матрицы 3*3 и больше

    //Создание матрицы порядка n - 1
    matrix_t minor;
    int rows_minor = (A->rows) - 1;
    int columns_minor = (A->columns) - 1;
    s21_create_matrix(rows_minor, columns_minor, &minor);

    //Результат определителя путем сложения миноров
    double det = 0;

    int num_rows = 0;
    int num_columns = 0;

    for (int i = 0; i < n; i++) {
      get_minor(&minor, A, num_rows,
                num_columns);  //Получение минора порядка n - 1
      det += pow(-1, i + 2) * A->matrix[0][i] *
             s21_get_determinant_minor(&minor, n - 1);
      num_rows++;
    }

    s21_remove_matrix(&minor);  //Очистка памяти матриц под миноры
    result = det;
  }
  return result;
}
