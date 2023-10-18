#include "s21_matrix_tests.h"

START_TEST(s21_add_test_1) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 2, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  err = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(2, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_2) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);
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
  correct_res.matrix[0][0] = -1.5 / -36;
  correct_res.matrix[1][0] = -1.5 / -36;
  correct_res.matrix[2][0] = 31.5 / -36;
  correct_res.matrix[0][1] = -3.6 / -36;
  correct_res.matrix[1][1] = 3.6 / -36;
  correct_res.matrix[2][1] = -3.6 / -36;
  correct_res.matrix[0][2] = -5. / -36;
  correct_res.matrix[1][2] = -5. / -36;
  correct_res.matrix[2][2] = -15. / -36;

  err = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(0, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_3) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);
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
  correct_res.matrix[0][0] = -1.5 / -36;
  correct_res.matrix[1][0] = -1.5 / -36;
  correct_res.matrix[2][0] = 31.5 / -36;
  correct_res.matrix[0][1] = -3.6 / -36;
  correct_res.matrix[1][1] = 3.6 / -36;
  correct_res.matrix[2][1] = -3.6 / -36;
  correct_res.matrix[0][2] = -5. / -36;
  correct_res.matrix[1][2] = -5. / -36;
  correct_res.matrix[2][2] = -14. / -36;

  err = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(0, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(0, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_4) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &correct_res);
  int err = 0;

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[1][0] = 5;
  matrix_1.matrix[2][0] = 3;
  matrix_1.matrix[0][1] = 1;
  matrix_1.matrix[1][1] = -5;
  matrix_1.matrix[2][1] = 3.3;
  matrix_1.matrix[0][2] = 0;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][2] = 0;
  correct_res.matrix[0][0] = -1.5 / -36;
  correct_res.matrix[1][0] = -1.5 / -36;
  correct_res.matrix[2][0] = 31.5 / -36;
  correct_res.matrix[0][1] = -3.6 / -36;
  correct_res.matrix[1][1] = 3.6 / -36;
  correct_res.matrix[2][1] = -3.6 / -36;
  correct_res.matrix[0][2] = -5. / -36;
  correct_res.matrix[1][2] = -5. / -36;
  correct_res.matrix[2][2] = -14. / -36;

  err = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(2, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&correct_res);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_5) {
  matrix_t matrix_1, result, correct_res;
  s21_create_matrix(-2, 3, &matrix_1);
  int err = 0;

  err = s21_inverse_matrix(&matrix_1, &result);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_6) {
  matrix_t A, result, res_origin;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  res_origin.matrix[0][0] = 1;
  res_origin.matrix[0][1] = -1;
  res_origin.matrix[0][2] = 1;
  res_origin.matrix[1][0] = -38;
  res_origin.matrix[1][1] = 41;
  res_origin.matrix[1][2] = -34;
  res_origin.matrix[2][0] = 27;
  res_origin.matrix[2][1] = -29;
  res_origin.matrix[2][2] = 24;
  s21_inverse_matrix(&A, &result);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], res_origin.matrix[i][j],
                              1e-7);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_7) {
  matrix_t A, result, res_origin;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 0.7;
  A.matrix[1][0] = -1;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 0.3;
  A.matrix[2][1] = -0.3;
  A.matrix[2][2] = 2;
  res_origin.matrix[0][0] = 45.0 / 289.0;
  res_origin.matrix[0][1] = -281.0 / 578.0;
  res_origin.matrix[0][2] = 195.0 / 289.0;
  res_origin.matrix[1][0] = 145.0 / 289.0;
  res_origin.matrix[1][1] = 379.0 / 578.0;
  res_origin.matrix[1][2] = -335.0 / 289.0;
  res_origin.matrix[2][0] = 15.0 / 289.0;
  res_origin.matrix[2][1] = 99.0 / 578.0;
  res_origin.matrix[2][2] = 65.0 / 289.0;
  s21_inverse_matrix(&A, &result);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], res_origin.matrix[i][j],
                              1e-7);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_8) {
  matrix_t A, result, res_origin;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res_origin);
  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;
  res_origin.matrix[0][0] = 44300.0 / 367429.0;
  res_origin.matrix[0][1] = -236300.0 / 367429.0;
  res_origin.matrix[0][2] = 200360.0 / 367429.0;
  res_origin.matrix[1][0] = 20600.0 / 367429.0;
  res_origin.matrix[1][1] = 56000.0 / 367429.0;
  res_origin.matrix[1][2] = -156483.0 / 367429.0;
  res_origin.matrix[2][0] = 30900.0 / 367429.0;
  res_origin.matrix[2][1] = 84000.0 / 367429.0;
  res_origin.matrix[2][2] = -51010.0 / 367429.0;
  s21_inverse_matrix(&A, &result);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], res_origin.matrix[i][j],
                              1e-7);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

// START_TEST(s21_add_test_9) {
//   matrix_t A, result, res_origin;
//   s21_create_matrix(1, 1, &A);
//   s21_create_matrix(1, 1, &res_origin);
//   A.matrix[0][0] = 777;
//   res_origin.matrix[0][0] = 1.0 / 777.0;
//   int check = s21_inverse_matrix(&A, &result);
//   int check_origin = 0;
//   ck_assert_double_eq_tol(res_origin.matrix[0][0], result.matrix[0][0],
//   1e-07); ck_assert_uint_eq(check, check_origin); s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&res_origin);
// }

START_TEST(s21_add_test_10) {
  matrix_t A, result;
  s21_create_matrix(-5, 5, &A);
  int check = s21_inverse_matrix(&A, &result);
  int check_origin = 1;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_11) {
  matrix_t A, result;
  s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 777;
  A.matrix[0][1] = 777;
  int check = s21_inverse_matrix(&A, &result);
  int check_origin = 2;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_12) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  int check = s21_inverse_matrix(&A, &result);
  int check_origin = 2;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_13) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;
  int check = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(check, 0);
  ck_assert_double_eq(0.2, B.matrix[0][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

void srunner_add_inverse_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Inverse");
  TCase *tc_inverse = tcase_create("Inverse");
  suite_add_tcase(save_v1, tc_inverse);

  // Remove fun()
  tcase_add_test(tc_inverse, s21_add_test_1);
  tcase_add_test(tc_inverse, s21_add_test_2);
  tcase_add_test(tc_inverse, s21_add_test_3);
  tcase_add_test(tc_inverse, s21_add_test_4);
  tcase_add_test(tc_inverse, s21_add_test_5);
  tcase_add_test(tc_inverse, s21_add_test_6);
  tcase_add_test(tc_inverse, s21_add_test_7);
  tcase_add_test(tc_inverse, s21_add_test_8);
  //   tcase_add_test(tc_inverse, s21_add_test_9);
  tcase_add_test(tc_inverse, s21_add_test_10);
  tcase_add_test(tc_inverse, s21_add_test_11);
  tcase_add_test(tc_inverse, s21_add_test_12);
  tcase_add_test(tc_inverse, s21_add_test_13);

  srunner_add_suite(sr, save_v1);
}