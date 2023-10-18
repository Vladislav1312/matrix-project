#include "s21_matrix_tests.h"

START_TEST(s21_add_test_1) {
  matrix_t matrix;

  int err = 0;
  err = s21_create_matrix(5, 5, &matrix);
  ck_assert_int_eq(0, err);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_add_test_2) {
  matrix_t matrix;

  int err = 0;
  err = s21_create_matrix(5, 10, &matrix);
  ck_assert_int_eq(0, err);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_add_test_3) {
  matrix_t matrix;

  int err = 0;
  err = s21_create_matrix(10, 5, &matrix);
  ck_assert_int_eq(0, err);
  s21_remove_matrix(&matrix);
}
START_TEST(s21_add_test_4) {
  matrix_t matrix;

  int err = 0;
  err = s21_create_matrix(0, 0, &matrix);
  ck_assert_int_eq(1, err);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_add_test_5) {
  matrix_t matrix;

  int err = 0;
  err = s21_create_matrix(0, 3, &matrix);
  ck_assert_int_eq(1, err);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_add_test_6) {
  matrix_t matrix;

  int err = 0;
  err = s21_create_matrix(-4, -4, &matrix);
  ck_assert_int_eq(1, err);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_add_test_7) {
  matrix_t matrix;

  int err = 0;
  err = s21_create_matrix(-4, 5, &matrix);
  ck_assert_int_eq(1, err);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_add_test_8) {
  matrix_t matrix;

  int err = 0;
  err = s21_create_matrix(4, -5, &matrix);
  ck_assert_int_eq(1, err);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_add_test_9) {
  matrix_t m1;

  int check = s21_create_matrix(1, 1, &m1);
  int check_origin = 0;
  s21_remove_matrix(&m1);
  ck_assert_int_eq(check, check_origin);
}

START_TEST(s21_add_test_10) {
  matrix_t m1;
  int check = s21_create_matrix(0, 15, &m1);
  int check_origin = 1;
  s21_remove_matrix(&m1);
  ck_assert_int_eq(check, check_origin);
}

START_TEST(s21_add_test_11) {
  matrix_t A = {0};
  int check = s21_create_matrix(3, 4, &A);
  int check_origin = 0;
  s21_remove_matrix(&A);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_add_test_12) {
  matrix_t A = {0};
  int check = s21_create_matrix(-3, 4, &A);
  int check_origin = 1;
  s21_remove_matrix(&A);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_add_test_13) {
  matrix_t A = {0};
  int check = s21_create_matrix(3, -4, &A);
  int check_origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_add_test_14) {
  matrix_t A = {0};
  int check = s21_create_matrix(0, 19, &A);
  int check_origin = 1;
  s21_remove_matrix(&A);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_add_test_15) {
  matrix_t A = {0};
  int check = s21_create_matrix(1, 1, &A);
  int check_origin = 0;
  s21_remove_matrix(&A);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_add_test_16) {
  matrix_t res = {0};
  ck_assert_int_eq(s21_create_matrix(7, 7, &res), 0);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_add_test_17) {
  matrix_t res;
  ck_assert_int_eq(s21_create_matrix(10, 15, &res), 0);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_add_test_18) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 75301501;
  s21_remove_matrix(&A);
  int check = (A.rows == 3) ? 0 : 1;
  int check_origin = 1;
  ck_assert_uint_eq(check, check_origin);
}
END_TEST

START_TEST(s21_add_test_19) {
  matrix_t res = {0};
  ck_assert_int_eq(s21_create_matrix(1, 0, &res), 1);
}
END_TEST

void srunner_add_create_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Create");
  TCase *tc_create = tcase_create("Create");
  suite_add_tcase(save_v1, tc_create);

  // Create fun()
  tcase_add_test(tc_create, s21_add_test_1);
  tcase_add_test(tc_create, s21_add_test_2);
  tcase_add_test(tc_create, s21_add_test_3);
  tcase_add_test(tc_create, s21_add_test_4);
  tcase_add_test(tc_create, s21_add_test_5);
  tcase_add_test(tc_create, s21_add_test_6);
  tcase_add_test(tc_create, s21_add_test_7);
  tcase_add_test(tc_create, s21_add_test_8);
  tcase_add_test(tc_create, s21_add_test_9);
  tcase_add_test(tc_create, s21_add_test_10);
  tcase_add_test(tc_create, s21_add_test_11);
  tcase_add_test(tc_create, s21_add_test_12);
  tcase_add_test(tc_create, s21_add_test_13);
  tcase_add_test(tc_create, s21_add_test_14);
  tcase_add_test(tc_create, s21_add_test_15);
  tcase_add_test(tc_create, s21_add_test_16);
  tcase_add_test(tc_create, s21_add_test_17);
  tcase_add_test(tc_create, s21_add_test_18);
  tcase_add_test(tc_create, s21_add_test_19);

  srunner_add_suite(sr, save_v1);
}