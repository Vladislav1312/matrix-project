#include "s21_matrix_tests.h"

START_TEST(s21_add_test_1) {
  int err = 0;
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(2, 3, &correct_res);

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 4;
  matrix_1.matrix[1][0] = 2;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[2][1] = 6;
  correct_res.matrix[0][0] = 1;
  correct_res.matrix[0][1] = 2;
  correct_res.matrix[0][2] = 3;
  correct_res.matrix[1][0] = 4;
  correct_res.matrix[1][1] = 5;
  correct_res.matrix[1][2] = 6;

  err = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(0, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_2) {
  int err = 0;
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(2, 3, &correct_res);

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 4;
  matrix_1.matrix[1][0] = 2;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[2][1] = 6;

  correct_res.matrix[0][0] = 1;
  correct_res.matrix[0][1] = 2;
  correct_res.matrix[0][2] = 3;
  correct_res.matrix[1][0] = 4;
  correct_res.matrix[1][1] = 5;
  correct_res.matrix[1][2] = 10;

  err = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(0, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(0, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_3) {
  int err = 0;
  matrix_t matrix_1, result;
  s21_create_matrix(3, 0, &matrix_1);

  err = s21_transpose(&matrix_1, &result);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_4) {
  matrix_t m1;
  matrix_t r;
  matrix_t origin;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 2, &m1);
  int check_2 = s21_create_matrix(2, 3, &origin);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 4;
  m1.matrix[1][0] = 2;
  m1.matrix[1][1] = 5;
  m1.matrix[2][0] = 3;
  m1.matrix[2][1] = 6;
  origin.matrix[0][0] = 1;
  origin.matrix[0][1] = 2;
  origin.matrix[0][2] = 3;
  origin.matrix[1][0] = 4;
  origin.matrix[1][1] = 5;
  origin.matrix[1][2] = 6;
  int result = s21_transpose(&m1, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}

START_TEST(s21_add_test_5) {
  matrix_t m1;
  matrix_t r;
  matrix_t origin;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 4;
  m1.matrix[0][2] = 7;
  m1.matrix[1][0] = 2;
  m1.matrix[1][1] = 5;
  m1.matrix[1][2] = 8;
  m1.matrix[2][0] = 3;
  m1.matrix[2][1] = 6;
  m1.matrix[2][2] = 9;
  origin.matrix[0][0] = 1;
  origin.matrix[0][1] = 2;
  origin.matrix[0][2] = 3;
  origin.matrix[1][0] = 4;
  origin.matrix[1][1] = 5;
  origin.matrix[1][2] = 6;
  origin.matrix[2][0] = 7;
  origin.matrix[2][1] = 8;
  origin.matrix[2][2] = 9;
  int result = s21_transpose(&m1, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}

START_TEST(s21_add_test_6) {
  matrix_t m1;
  matrix_t r;
  matrix_t origin;
  int check_origin = 0;
  int check_1 = s21_create_matrix(1, 1, &m1);
  int check_2 = s21_create_matrix(1, 1, &origin);
  m1.matrix[0][0] = 1.1;
  origin.matrix[0][0] = 1.1;
  int result = s21_transpose(&m1, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}

START_TEST(s21_add_test_7) {
  matrix_t A, result, result_origin;
  s21_create_matrix(5, 4, &A);
  s21_create_matrix(4, 5, &result_origin);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[0][3] = -4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 14;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  A.matrix[2][3] = -1;
  A.matrix[3][0] = 10;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 9;
  A.matrix[3][3] = -3;
  A.matrix[4][0] = -3;
  A.matrix[4][1] = 3;
  A.matrix[4][2] = 1;
  A.matrix[4][3] = 5;
  result_origin.matrix[0][0] = 2;
  result_origin.matrix[0][1] = 6;
  result_origin.matrix[0][2] = 5;
  result_origin.matrix[0][3] = 10;
  result_origin.matrix[0][4] = -3;
  result_origin.matrix[1][0] = 5;
  result_origin.matrix[1][1] = 3;
  result_origin.matrix[1][2] = -2;
  result_origin.matrix[1][3] = 3;
  result_origin.matrix[1][4] = 3;
  result_origin.matrix[2][0] = 7;
  result_origin.matrix[2][1] = 4;
  result_origin.matrix[2][2] = -3;
  result_origin.matrix[2][3] = 9;
  result_origin.matrix[2][4] = 1;
  result_origin.matrix[3][0] = -4;
  result_origin.matrix[3][1] = 14;
  result_origin.matrix[3][2] = -1;
  result_origin.matrix[3][3] = -3;
  result_origin.matrix[3][4] = 5;
  s21_transpose(&A, &result);
  for (int i = 0; i < result_origin.rows; i++) {
    for (int j = 0; j < result_origin.columns; j++) {
      ck_assert_uint_eq(result_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_origin);
}

START_TEST(s21_add_test_8) {
  matrix_t A, result, res_origin;
  s21_create_matrix(4, 7, &A);
  s21_create_matrix(7, 4, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
    }
  }
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      res_origin.matrix[i][j] = j;
    }
  }
  s21_transpose(&A, &result);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_9) {
  matrix_t A, result;
  s21_create_matrix(4, -7, &A);
  int check = s21_transpose(&A, &result);
  int check_origin = 1;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}

void srunner_add_transpose_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Transpose");
  TCase *tc_transpose = tcase_create("Transpose");
  suite_add_tcase(save_v1, tc_transpose);

  // Transpose fun()
  tcase_add_test(tc_transpose, s21_add_test_1);
  tcase_add_test(tc_transpose, s21_add_test_2);
  tcase_add_test(tc_transpose, s21_add_test_3);
  tcase_add_test(tc_transpose, s21_add_test_4);
  tcase_add_test(tc_transpose, s21_add_test_5);
  tcase_add_test(tc_transpose, s21_add_test_6);
  tcase_add_test(tc_transpose, s21_add_test_7);
  tcase_add_test(tc_transpose, s21_add_test_8);
  tcase_add_test(tc_transpose, s21_add_test_9);

  srunner_add_suite(sr, save_v1);
}