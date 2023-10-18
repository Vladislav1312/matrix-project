#include <stdlib.h>

#include "s21_matrix.h"

//Результирующий код:
// 0 - OK;
// 1 - Ошибка, некорректная матрица;
// 2 - Ошибка вычисления(несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и тд.);

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = 0;  //Ошибка компиляции - OK

  if (rows > 0 && columns > 0) {
    result->matrix = (double **)calloc(
        rows,
        (sizeof(double *)));  //Выделение памяти на кол-во указателей строк
    result->rows = rows;
    result->columns = columns;
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(
          columns, sizeof(double));  //Выделение памяти на кол-во столбцов
    }
  } else {
    flag = 1;  //Ошибка компиляции - Некорректная матрица;
    result->matrix = NULL;
    result->rows = 0;
    result->columns = 0;
  }
  return flag;
}