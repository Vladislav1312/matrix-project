# matrix-project

В данном проекте реализована своя библиотека для обработки числовых матриц на языке программирования Си.

Проект включает в себя следующие функции:

Создание матриц (create_matrix)<br/>
int s21_create_matrix(int rows, int columns, matrix_t *result);<br/>

Очистка матриц (remove_matrix)<br/>
void s21_remove_matrix(matrix_t *A);<br/>

Сравнение матриц (eq_matrix)<br/>
int s21_eq_matrix(matrix_t *A, matrix_t *B);<br/>

Сложение (sum_matrix) и вычитание матриц (sub_matrix)<br/>
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);<br/>
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);<br/>

Умножение матрицы на число (mult_number). Умножение двух матриц (mult_matrix)<br/>
int s21_mult_number(matrix_t *A, double number, matrix_t *result);<br/>
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);<br/>

Транспонирование матрицы (transpose)<br/>
int s21_transpose(matrix_t *A, matrix_t *result);<br/>

Минор матрицы и матрица алгебраических дополнений (calc_complements)<br/>
int s21_calc_complements(matrix_t *A, matrix_t *result);<br/>

Определитель матрицы (determinant)<br/>
int s21_determinant(matrix_t *A, double *result);<br/>

Обратная матрица (inverse_matrix)<br/>
int s21_inverse_matrix(matrix_t *A, matrix_t *result);<br/>

А также тестовые и заголовочные файлы:

create_matrix_tests.c
remove_matrix_tests.c
eq_matrix_tests.c
sum_matrix_tests.c
sub_matrix_tests.c
mult_number_tests.c
mult_matrix_tests.c
transpose_tests.c
calc_complements_tests.c
determinant_tests.c
inverse_matrix_tests.c
s21_all_tests.h
s21_matrix.h
Для тестирование кода и создания отчета о покрытии - создаются обьектые файлы и статическая библиотека s21_matrix.a
