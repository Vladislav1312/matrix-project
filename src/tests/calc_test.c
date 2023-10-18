#include "s21_matrix_tests.h"

START_TEST(s21_add_test_1) {
  int err = 0;
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);

  err = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(2, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_2) {
  int err = 0;
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[0][1] = 1;
  matrix_1.matrix[1][1] = -5;
  matrix_1.matrix[2][1] = 3.3;
  matrix_1.matrix[0][2] = -1;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][2] = 0.3;
  correct_res.matrix[0][0] = -1.5;
  correct_res.matrix[0][1] = -1.5;
  correct_res.matrix[0][2] = 31.5;
  correct_res.matrix[1][0] = -3.6;
  correct_res.matrix[1][1] = 3.6;
  correct_res.matrix[1][2] = -3.6;
  correct_res.matrix[2][0] = -5;
  correct_res.matrix[2][1] = -5;
  correct_res.matrix[2][2] = -15;

  err = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(0, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_3) {
  int err = 0;
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[0][1] = 1;
  matrix_1.matrix[1][1] = -5;
  matrix_1.matrix[2][1] = 3.3;
  matrix_1.matrix[0][2] = -1;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][2] = 0.3;
  correct_res.matrix[0][0] = -1.5;
  correct_res.matrix[0][1] = -1.5;
  correct_res.matrix[0][2] = 31.5;
  correct_res.matrix[1][0] = -3.6;
  correct_res.matrix[1][1] = 3.6;
  correct_res.matrix[1][2] = 100;
  correct_res.matrix[2][0] = -5;
  correct_res.matrix[2][1] = -5;
  correct_res.matrix[2][2] = -15;

  err = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(0, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(0, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_4) {
  int err = 0;
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(-1, 3, &matrix_1);

  err = s21_calc_complements(&matrix_1, &result);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_5) {
  matrix_t A, result, res_origin;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  res_origin.matrix[0][0] = 0;
  res_origin.matrix[0][1] = 10;
  res_origin.matrix[0][2] = -20;
  res_origin.matrix[1][0] = 4;
  res_origin.matrix[1][1] = -14;
  res_origin.matrix[1][2] = 8;
  res_origin.matrix[2][0] = -8;
  res_origin.matrix[2][1] = -2;
  res_origin.matrix[2][2] = 4;
  s21_calc_complements(&A, &result);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_6) {
  matrix_t A, result, res_origin;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &res_origin);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  res_origin.matrix[0][0] = 3;
  res_origin.matrix[0][1] = -6;
  res_origin.matrix[1][0] = -4;
  res_origin.matrix[1][1] = 2;
  s21_calc_complements(&A, &result);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_7) {
  matrix_t A, result, res_origin;
  s21_create_matrix(-2, 2, &A);
  s21_create_matrix(2, 2, &res_origin);
  int check = s21_calc_complements(&A, &result);
  int check_origin = 1;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_8) {
  matrix_t A, result, res_origin;
  s21_create_matrix(2, 4, &A);
  s21_create_matrix(2, 2, &res_origin);
  int check = s21_calc_complements(&A, &result);
  int check_origin = 2;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

void srunner_add_calc_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Сalc");
  TCase *tc_calc = tcase_create("Сalc");
  suite_add_tcase(save_v1, tc_calc);

  // Calc fun()
  tcase_add_test(tc_calc, s21_add_test_1);
  tcase_add_test(tc_calc, s21_add_test_2);
  tcase_add_test(tc_calc, s21_add_test_3);
  tcase_add_test(tc_calc, s21_add_test_4);
  tcase_add_test(tc_calc, s21_add_test_5);
  tcase_add_test(tc_calc, s21_add_test_6);
  tcase_add_test(tc_calc, s21_add_test_7);
  tcase_add_test(tc_calc, s21_add_test_8);
  srunner_add_suite(sr, save_v1);
}