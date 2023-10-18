#include "s21_matrix_tests.h"

START_TEST(s21_add_test_1) {
  matrix_t matrix_1;
  s21_create_matrix(3, 2, &matrix_1);
  double result;
  int err = 0;

  err = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(2, err);

  s21_remove_matrix(&matrix_1);
}

START_TEST(s21_add_test_2) {
  matrix_t matrix_1;
  s21_create_matrix(3, 3, &matrix_1);
  double result;
  int err = 0;

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[0][1] = 1;
  matrix_1.matrix[1][1] = -5;
  matrix_1.matrix[2][1] = 3.3;
  matrix_1.matrix[0][2] = -1;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][2] = 0.3;

  err = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(0, err);
  ck_assert_int_eq(1, result == -36);

  s21_remove_matrix(&matrix_1);
}

START_TEST(s21_add_test_3) {
  matrix_t matrix_1;
  s21_create_matrix(2, 2, &matrix_1);
  double result;
  int err = 0;

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[0][1] = 3;
  matrix_1.matrix[1][1] = 1;

  err = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(0, err);
  ck_assert_int_eq(1, result == -13);

  s21_remove_matrix(&matrix_1);
}

START_TEST(s21_add_test_4) {
  matrix_t matrix_1;
  s21_create_matrix(-1, 2, &matrix_1);
  double result;
  int err = 0;

  err = s21_determinant(&matrix_1, &result);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
}

START_TEST(s21_add_test_5) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = -5;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 3;
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = 43;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_uint_eq(result, result_origin);
  s21_remove_matrix(&A);
}

START_TEST(s21_add_test_6) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 3;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 2;
  A.matrix[2][0] = -5;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 3;
  A.matrix[2][3] = 3;
  A.matrix[3][0] = -12.12;
  A.matrix[3][1] = 12.12;
  A.matrix[3][2] = 2.12;
  A.matrix[3][3] = -2.12;
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = -182.32;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_uint_eq(result, result_origin);
  s21_remove_matrix(&A);
}

START_TEST(s21_add_test_7) {
  matrix_t A;
  double result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = 1;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_uint_eq(result, result_origin);
  s21_remove_matrix(&A);
}

START_TEST(s21_add_test_8) {
  matrix_t A;
  double result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 55.5;
  A.matrix[0][1] = 14.4;
  A.matrix[1][0] = -0.752;
  A.matrix[1][1] = 156.2;
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = 8679.9288;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_uint_eq(result, result_origin);
  s21_remove_matrix(&A);
}

START_TEST(s21_add_test_9) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 11.1;
  A.matrix[0][1] = 2.2;
  A.matrix[0][2] = 3.3;
  A.matrix[0][3] = 4.4;
  A.matrix[1][0] = 8.8;
  A.matrix[1][1] = -9.9;
  A.matrix[1][2] = 10.1;
  A.matrix[1][3] = 11.11;
  A.matrix[2][0] = 15.15;
  A.matrix[2][1] = 16.16;
  A.matrix[2][2] = 17.17;
  A.matrix[2][3] = 18.18;
  A.matrix[3][0] = -22.22;
  A.matrix[3][1] = 23.23;
  A.matrix[3][2] = 24.24;
  A.matrix[3][3] = 25.25;
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = -11770.2443124;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_double_eq_tol(result, result_origin, 1e-7);
  s21_remove_matrix(&A);
}

START_TEST(s21_add_test_10) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);
  int check = s21_determinant(&A, &result);
  int check_origin = 0;
  double result_origin = 0;
  ck_assert_uint_eq(check, check_origin);
  ck_assert_double_eq_tol(result, result_origin, 1e-7);
  s21_remove_matrix(&A);
}

START_TEST(s21_add_test_11) {
  matrix_t A;
  double result;
  s21_create_matrix(5, 4, &A);
  int check = s21_determinant(&A, &result);
  int check_origin = 2;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
}

START_TEST(s21_add_test_12) {
  matrix_t A;
  double result;
  s21_create_matrix(-4, 4, &A);
  int check = s21_determinant(&A, &result);
  int check_origin = 1;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
}

START_TEST(s21_add_test_13) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 5;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 4;
  A.matrix[2][0] = 8;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 0;
  A.matrix[2][3] = 4;
  A.matrix[3][0] = 6;
  A.matrix[3][1] = 8;
  A.matrix[3][2] = 9;
  A.matrix[3][3] = 4;
  int check = s21_determinant(&A, &result);
  ck_assert_int_eq(check, 0);
  ck_assert_double_eq_tol(result, 438.0, 1e-7);
  s21_remove_matrix(&A);
}

START_TEST(s21_add_test_14) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[1][0] = 0;
  A.matrix[2][0] = 0;
  A.matrix[0][1] = 3;
  A.matrix[1][1] = 5;
  A.matrix[2][1] = 9;
  A.matrix[0][2] = 1;
  A.matrix[1][2] = 56.23456;
  A.matrix[2][2] = 12345432.343;
  int check = s21_determinant(&A, &result);
  ck_assert_int_eq(check, 0);
  ck_assert_double_eq_tol(result, 0.0, 1e-7);
  s21_remove_matrix(&A);
}

START_TEST(s21_add_test_15) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 123.456;
  A.matrix[1][0] = 123.455;
  A.matrix[2][0] = 123.454;
  A.matrix[0][1] = 123.453;
  A.matrix[1][1] = 123.452;
  A.matrix[2][1] = 123.451;
  A.matrix[0][2] = 123.450;
  A.matrix[1][2] = 1113.449;
  A.matrix[2][2] = 15.448;
  int check = s21_determinant(&A, &result);
  ck_assert_int_eq(check, 0);
  ck_assert_double_eq_tol(result, 0.006264, 1e-7 * 10.0);
  s21_remove_matrix(&A);
}

void srunner_add_determinant_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Determinant");
  TCase *tc_determinant = tcase_create("Determinant");
  suite_add_tcase(save_v1, tc_determinant);

  // Determinant fun()
  tcase_add_test(tc_determinant, s21_add_test_1);
  tcase_add_test(tc_determinant, s21_add_test_2);
  tcase_add_test(tc_determinant, s21_add_test_3);
  tcase_add_test(tc_determinant, s21_add_test_4);
  tcase_add_test(tc_determinant, s21_add_test_5);
  tcase_add_test(tc_determinant, s21_add_test_6);
  tcase_add_test(tc_determinant, s21_add_test_7);
  tcase_add_test(tc_determinant, s21_add_test_8);
  tcase_add_test(tc_determinant, s21_add_test_9);
  tcase_add_test(tc_determinant, s21_add_test_10);
  tcase_add_test(tc_determinant, s21_add_test_11);
  tcase_add_test(tc_determinant, s21_add_test_12);
  tcase_add_test(tc_determinant, s21_add_test_13);
  tcase_add_test(tc_determinant, s21_add_test_14);
  tcase_add_test(tc_determinant, s21_add_test_15);

  srunner_add_suite(sr, save_v1);
}