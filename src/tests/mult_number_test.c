#include "s21_matrix_tests.h"

START_TEST(s21_add_test_1) {
  int err = 0;
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &correct_res);

  matrix_1.matrix[0][0] = 1.1;
  matrix_1.matrix[0][1] = 2.0;
  matrix_1.matrix[1][0] = 3.0;
  matrix_1.matrix[1][1] = 4.0;
  correct_res.matrix[0][0] = 2.2;
  correct_res.matrix[0][1] = 4.0;
  correct_res.matrix[1][0] = 6.0;
  correct_res.matrix[1][1] = 8.0;

  err = s21_mult_number(&matrix_1, 2, &result);
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
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &correct_res);

  matrix_1.matrix[0][0] = 1.1;
  matrix_1.matrix[0][1] = 2.0;
  matrix_1.matrix[1][0] = 3.0;
  matrix_1.matrix[1][1] = 4.0;

  correct_res.matrix[0][0] = 2.2;
  correct_res.matrix[0][1] = 4.0;
  correct_res.matrix[1][0] = 50.0;
  correct_res.matrix[1][1] = 8.0;

  err = s21_mult_number(&matrix_1, 2, &result);
  ck_assert_int_eq(0, err);

  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(0, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_3) {
  int err = 0;
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(2, -5, &matrix_1);

  err = s21_mult_number(&matrix_1, 2, &result);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_4) {
  matrix_t m1;
  matrix_t origin;
  matrix_t r;
  double num = 2.0;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  origin.matrix[0][0] = 0.2;
  origin.matrix[0][1] = 0.4;
  origin.matrix[0][2] = 0.6;
  origin.matrix[1][0] = 0.8;
  origin.matrix[1][1] = 1.0;
  origin.matrix[1][2] = 1.2;
  origin.matrix[2][0] = 1.4;
  origin.matrix[2][1] = 1.6;
  origin.matrix[2][2] = 1.8;
  int result = s21_mult_number(&m1, num, &r);
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
  double num = 0.0;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  int result = s21_mult_number(&m1, num, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(0.0, r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&r);
}

START_TEST(s21_add_test_6) {
  matrix_t m1;
  matrix_t r;
  double num = 1.0;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  int result = s21_mult_number(&m1, num, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(m1.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&r);
}

START_TEST(s21_add_test_7) {
  matrix_t A, result, res_origin;
  double num = 2.0;
  int check_origin = 0;
  int check_1 = s21_create_matrix(5, 4, &A);
  int check_3 = s21_create_matrix(5, 4, &res_origin);
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
  res_origin.matrix[0][0] = 4;
  res_origin.matrix[0][1] = 10;
  res_origin.matrix[0][2] = 14;
  res_origin.matrix[0][3] = -8;
  res_origin.matrix[1][0] = 12;
  res_origin.matrix[1][1] = 6;
  res_origin.matrix[1][2] = 8;
  res_origin.matrix[1][3] = 28;
  res_origin.matrix[2][0] = 10;
  res_origin.matrix[2][1] = -4;
  res_origin.matrix[2][2] = -6;
  res_origin.matrix[2][3] = -2;
  res_origin.matrix[3][0] = 20;
  res_origin.matrix[3][1] = 6;
  res_origin.matrix[3][2] = 18;
  res_origin.matrix[3][3] = -6;
  res_origin.matrix[4][0] = -6;
  res_origin.matrix[4][1] = 6;
  res_origin.matrix[4][2] = 2;
  res_origin.matrix[4][3] = 10;
  int check = s21_mult_number(&A, num, &result);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_8) {
  matrix_t A, result, res_origin;
  double num = 4.25;
  int check_origin = 0;
  int check_1 = s21_create_matrix(5, 4, &A);
  int check_3 = s21_create_matrix(5, 4, &res_origin);
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
  res_origin.matrix[0][0] = 8.5;
  res_origin.matrix[0][1] = 21.25;
  res_origin.matrix[0][2] = 29.75;
  res_origin.matrix[0][3] = -17;
  res_origin.matrix[1][0] = 25.5;
  res_origin.matrix[1][1] = 12.75;
  res_origin.matrix[1][2] = 17;
  res_origin.matrix[1][3] = 59.5;
  res_origin.matrix[2][0] = 21.25;
  res_origin.matrix[2][1] = -8.5;
  res_origin.matrix[2][2] = -12.75;
  res_origin.matrix[2][3] = -4.25;
  res_origin.matrix[3][0] = 42.5;
  res_origin.matrix[3][1] = 12.75;
  res_origin.matrix[3][2] = 38.25;
  res_origin.matrix[3][3] = -12.75;
  res_origin.matrix[4][0] = -12.75;
  res_origin.matrix[4][1] = 12.75;
  res_origin.matrix[4][2] = 4.25;
  res_origin.matrix[4][3] = 21.25;
  int check = s21_mult_number(&A, num, &result);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(check, check_origin);
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
  matrix_t A, result, res_origin;
  double num = 4.25;
  int check_origin = 1;
  s21_create_matrix(-5, 4, &A);
  s21_create_matrix(5, 4, &res_origin);
  int check = s21_mult_number(&A, num, &result);
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_10) {
  matrix_t A, result, res_origin;
  double num = 4.25;
  int check_origin = 1;
  s21_create_matrix(0, 0, &A);
  int check = s21_mult_number(&A, num, &result);
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

void srunner_add_mult_number_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Mult_number");
  TCase *tc_mult_number = tcase_create("Mult_number");
  suite_add_tcase(save_v1, tc_mult_number);

  // Mult_number fun()
  tcase_add_test(tc_mult_number, s21_add_test_1);
  tcase_add_test(tc_mult_number, s21_add_test_2);
  tcase_add_test(tc_mult_number, s21_add_test_3);
  tcase_add_test(tc_mult_number, s21_add_test_4);
  tcase_add_test(tc_mult_number, s21_add_test_5);
  tcase_add_test(tc_mult_number, s21_add_test_6);
  tcase_add_test(tc_mult_number, s21_add_test_7);
  tcase_add_test(tc_mult_number, s21_add_test_8);
  tcase_add_test(tc_mult_number, s21_add_test_9);
  tcase_add_test(tc_mult_number, s21_add_test_10);

  srunner_add_suite(sr, save_v1);
}