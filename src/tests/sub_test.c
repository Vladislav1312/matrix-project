#include "s21_matrix_tests.h"

START_TEST(s21_add_test_4) {
  int err = 0;
  matrix_t matrix_1, matrix_2, result;

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);

  err = s21_sub_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(0, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_5) {
  int err = 0;
  matrix_t matrix_1, matrix_2, result, correct_res;

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  s21_create_matrix(2, 2, &correct_res);

  matrix_1.matrix[0][0] = 1.2;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 4;
  matrix_2.matrix[0][0] = 1;
  matrix_2.matrix[0][1] = 2;
  matrix_2.matrix[1][0] = 3;
  matrix_2.matrix[1][1] = 4;
  correct_res.matrix[0][0] = 0.2;
  correct_res.matrix[0][1] = 0;
  correct_res.matrix[1][0] = 0;
  correct_res.matrix[1][1] = 0;

  err = s21_sub_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(0, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_6) {
  int err = 0;
  matrix_t matrix_1, matrix_2, result, correct_res;

  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  s21_create_matrix(2, 2, &correct_res);

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 4;
  matrix_2.matrix[0][0] = 1;
  matrix_2.matrix[0][1] = 2;
  matrix_2.matrix[1][0] = 3;
  matrix_2.matrix[1][1] = 4;
  correct_res.matrix[0][0] = 0;
  correct_res.matrix[0][1] = 0;
  correct_res.matrix[1][0] = 0;
  correct_res.matrix[1][1] = 0;

  err = s21_sub_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(0, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_7) {
  int err = 0;
  matrix_t matrix_1, matrix_2, result, correct_res;

  s21_create_matrix(2, -10, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  s21_create_matrix(2, 2, &correct_res);

  matrix_2.matrix[0][0] = 1;
  matrix_2.matrix[0][1] = 2;
  matrix_2.matrix[1][0] = 3;
  matrix_2.matrix[1][1] = 4;

  correct_res.matrix[0][0] = 2;
  correct_res.matrix[0][1] = 4;
  correct_res.matrix[1][0] = 22;
  correct_res.matrix[1][1] = 8;

  err = s21_sub_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_8) {
  int err = 0;
  matrix_t matrix_1, matrix_2, result, correct_res;

  s21_create_matrix(2, 6, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  s21_create_matrix(2, 2, &correct_res);

  err = s21_sub_matrix(&matrix_1, &matrix_2, &result);
  ck_assert_int_eq(2, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}

START_TEST(s21_add_test_9) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = 1.0;
  m2.matrix[0][1] = 2.0;
  m2.matrix[0][2] = 3.0;
  m2.matrix[1][0] = 4.0;
  m2.matrix[1][1] = 5.0;
  m2.matrix[1][2] = 6.0;
  m2.matrix[2][0] = 7.0;
  m2.matrix[2][1] = 8.0;
  m2.matrix[2][2] = 9.0;
  origin.matrix[0][0] = -0.9;
  origin.matrix[0][1] = -1.8;
  origin.matrix[0][2] = -2.7;
  origin.matrix[1][0] = -3.6;
  origin.matrix[1][1] = -4.5;
  origin.matrix[1][2] = -5.4;
  origin.matrix[2][0] = -6.3;
  origin.matrix[2][1] = -7.2;
  origin.matrix[2][2] = -8.1;
  int result = s21_sub_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}

START_TEST(s21_add_test_10) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = 0.0;
  m2.matrix[0][1] = 0.0;
  m2.matrix[0][2] = 0.0;
  m2.matrix[1][0] = 0.0;
  m2.matrix[1][1] = 0.0;
  m2.matrix[1][2] = 0.0;
  m2.matrix[2][0] = 0.0;
  m2.matrix[2][1] = 0.0;
  m2.matrix[2][2] = 0.0;
  origin.matrix[0][0] = 0.1;
  origin.matrix[0][1] = 0.2;
  origin.matrix[0][2] = 0.3;
  origin.matrix[1][0] = 0.4;
  origin.matrix[1][1] = 0.5;
  origin.matrix[1][2] = 0.6;
  origin.matrix[2][0] = 0.7;
  origin.matrix[2][1] = 0.8;
  origin.matrix[2][2] = 0.9;
  int result = s21_sub_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}

START_TEST(s21_add_test_11) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = 1.0;
  m2.matrix[0][1] = 2.0;
  m2.matrix[0][2] = 3.0;
  m2.matrix[1][0] = 4.0;
  m2.matrix[1][1] = 5.0;
  m2.matrix[1][2] = 6.0;
  m2.matrix[2][0] = 7.0;
  m2.matrix[2][1] = 8.0;
  m2.matrix[2][2] = 9.0;
  origin.matrix[0][0] = -0.9;
  origin.matrix[0][1] = -1.8;
  origin.matrix[0][2] = -2.7;
  origin.matrix[1][0] = -3.6;
  origin.matrix[1][1] = -4.5;
  origin.matrix[1][2] = -5.4;
  origin.matrix[2][0] = -6.3;
  origin.matrix[2][1] = -7.2;
  origin.matrix[2][2] = -8.1;
  int result = s21_sub_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}

START_TEST(s21_add_test_12) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = 0.0;
  m2.matrix[0][1] = 0.0;
  m2.matrix[0][2] = 0.0;
  m2.matrix[1][0] = 0.0;
  m2.matrix[1][1] = 0.0;
  m2.matrix[1][2] = 0.0;
  m2.matrix[2][0] = 0.0;
  m2.matrix[2][1] = 0.0;
  m2.matrix[2][2] = 0.0;
  origin.matrix[0][0] = 0.1;
  origin.matrix[0][1] = 0.2;
  origin.matrix[0][2] = 0.3;
  origin.matrix[1][0] = 0.4;
  origin.matrix[1][1] = 0.5;
  origin.matrix[1][2] = 0.6;
  origin.matrix[2][0] = 0.7;
  origin.matrix[2][1] = 0.8;
  origin.matrix[2][2] = 0.9;
  int result = s21_sub_matrix(&m2, &m1, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(-(origin.matrix[i][j]), r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}

START_TEST(s21_add_test_13) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], -2);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_14) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 0;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_15) {
  matrix_t result, B, A;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 2;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_16) {
  matrix_t result, B, A;
  s21_create_matrix(-2, 2, &A);
  s21_create_matrix(2, 2, &B);
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 1;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_17) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(-2, 2, &B);
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 1;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(s21_add_test_18) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &res_origin);
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
  B.matrix[0][0] = 8;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 5;
  B.matrix[1][0] = -7;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = 1;
  B.matrix[1][3] = 1;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 3;
  B.matrix[2][2] = 4;
  B.matrix[2][3] = -4;
  B.matrix[3][0] = 10;
  B.matrix[3][1] = 3;
  B.matrix[3][2] = 9;
  B.matrix[3][3] = -3;
  res_origin.matrix[0][0] = -6;
  res_origin.matrix[0][1] = -3;
  res_origin.matrix[0][2] = 4;
  res_origin.matrix[0][3] = -9;
  res_origin.matrix[1][0] = 13;
  res_origin.matrix[1][1] = -4;
  res_origin.matrix[1][2] = 3;
  res_origin.matrix[1][3] = 13;
  res_origin.matrix[2][0] = -2;
  res_origin.matrix[2][1] = -5;
  res_origin.matrix[2][2] = -7;
  res_origin.matrix[2][3] = 3;
  res_origin.matrix[3][0] = 0;
  res_origin.matrix[3][1] = 0;
  res_origin.matrix[3][2] = 0;
  res_origin.matrix[3][3] = 0;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_19) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &res_origin);
  A.matrix[0][0] = 2.987654;
  A.matrix[0][1] = -5.3456;
  A.matrix[1][0] = 6.23;
  A.matrix[1][1] = -3.9292;
  B.matrix[0][0] = 4.838;
  B.matrix[0][1] = 8.0987;
  B.matrix[1][0] = -8;
  B.matrix[1][1] = -0.921;
  res_origin.matrix[0][0] = -1.850346;
  res_origin.matrix[0][1] = -13.4443;
  res_origin.matrix[1][0] = 14.23;
  res_origin.matrix[1][1] = -3.0082;
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_20) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 4 * i;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = 2 * i;
    }
  }
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      res_origin.matrix[i][j] = i * 2;
    }
  }
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(s21_add_test_21) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(5, 4, &A);
  s21_create_matrix(5, 4, &B);
  s21_create_matrix(5, 4, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
      res_origin.matrix[i][j] = i;
    }
  }
  int check = s21_sub_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_uint_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

void srunner_add_sub_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Sub");
  TCase *tc_sub = tcase_create("Sub");
  suite_add_tcase(save_v1, tc_sub);

  // Sub fun()
  tcase_add_test(tc_sub, s21_add_test_4);
  tcase_add_test(tc_sub, s21_add_test_5);
  tcase_add_test(tc_sub, s21_add_test_6);
  tcase_add_test(tc_sub, s21_add_test_7);
  tcase_add_test(tc_sub, s21_add_test_8);
  tcase_add_test(tc_sub, s21_add_test_9);
  tcase_add_test(tc_sub, s21_add_test_10);
  tcase_add_test(tc_sub, s21_add_test_11);
  tcase_add_test(tc_sub, s21_add_test_12);
  tcase_add_test(tc_sub, s21_add_test_13);
  tcase_add_test(tc_sub, s21_add_test_14);
  tcase_add_test(tc_sub, s21_add_test_15);
  tcase_add_test(tc_sub, s21_add_test_16);
  tcase_add_test(tc_sub, s21_add_test_17);
  tcase_add_test(tc_sub, s21_add_test_18);
  tcase_add_test(tc_sub, s21_add_test_19);
  tcase_add_test(tc_sub, s21_add_test_20);
  tcase_add_test(tc_sub, s21_add_test_21);

  srunner_add_suite(sr, save_v1);
}