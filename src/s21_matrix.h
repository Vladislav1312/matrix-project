#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

double s21_get_determinant_minor(matrix_t *A, int n);
void get_minor(matrix_t *minor_matrix, matrix_t *A, int row_minor,
               int column_minor);

//Вывод матрицы +
void s21_print_matrix(matrix_t *A);

//Ввод значений в матрицу +
void s21_add_value_matrix(matrix_t *A);

// Создание матриц +
int s21_create_matrix(int rows, int columns, matrix_t *result);

// Очистка матриц +
void s21_remove_matrix(matrix_t *A);

// Сравнение матриц +
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// Сложение матриц +
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Вычитание матриц +
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Умножение матрицы на число +
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// Умножение двух матриц +
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Транспонирование матрицы +
int s21_transpose(matrix_t *A, matrix_t *result);

// Минор матрицы и матрица алгебраических дополнений +
int s21_calc_complements(matrix_t *A, matrix_t *result);

// Определитель матрицы +
int s21_determinant(matrix_t *A, double *result);

// Обратная матрица +
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif