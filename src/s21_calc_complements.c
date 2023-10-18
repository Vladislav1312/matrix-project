#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

//Результирующий код:
// 0 - OK;
// 1 - Ошибка, некорректная матрица;
// 2 - Ошибка вычисления(несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и тд.);

//Минор и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = 0;  //Ошибка компиляции - OK

  if (A->matrix == NULL &&
      (A->rows <= 0 || A->columns <= 0)) {  //Матрица == NULL
    flag = 1;
    result->matrix = NULL;
  } else if (A->rows !=
             A->columns) {  ////Матрица, для которой нельзя провести вычисления
    flag = 2;
    result->matrix = NULL;
  }

  if (!flag) {
    s21_create_matrix(A->rows, A->columns, result);
    matrix_t minor;
    int rows_minor = (A->rows) - 1;
    int columns_minor = (A->columns) - 1;
    s21_create_matrix(rows_minor, columns_minor, &minor);

    int num_rows = 0;
    int num_columns = 0;

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        get_minor(&minor, A, num_rows,
                  num_columns);  //Получение минора элемента матрицы
        double determinant_minor = 0;  //Определитель минора элемента
        int deter = s21_determinant(
            &minor, &determinant_minor);  //Получение определителя
        if (deter == 0) {
          result->matrix[i][j] =
              pow(-1.0, i + j) *
              determinant_minor;  //Занесение определителя в результат
          num_rows++;
        }
      }
      num_columns++;
      num_rows = 0;
    }
    s21_remove_matrix(&minor);
  }

  return flag;
}

void get_minor(matrix_t *minor_matrix, matrix_t *A, int row_minor,
               int column_minor) {
  int x = 0, y = 0;  //Индексы minor_matrix

  for (int i = 0; i < A->rows; i++) {
    if (i == column_minor) {  //Если в строке встречается столбец column_minor
      continue;
    }
    for (int j = 0; j < A->columns; j++) {
      if (j == row_minor) {  //Если в столбце встречается строка row_minor
        continue;
      }
      minor_matrix->matrix[x][y] =
          A->matrix[i][j];  //Заносим значение в матрицу minor
      y++;
    }
    x++;
    y = 0;
  }
}