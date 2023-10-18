#include "s21_matrix_tests.h"

START_TEST(s21_add_test_1) {
  matrix_t matrix_r;
  int err = 0;

  err = s21_create_matrix(3, 3, &matrix_r);
  s21_remove_matrix(&matrix_r);

  ck_assert_int_eq(err, 0);
}

START_TEST(s21_add_test_2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 75301501;
  s21_remove_matrix(&A);
  int check = (A.rows == 3) ? 0 : 1;
  int check_origin = 1;
  ck_assert_uint_eq(check, check_origin);
}

START_TEST(s21_add_test_3) {
  int err = 0;

  matrix_t A;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.353534;
  A.matrix[0][1] = 23.3432;
  A.matrix[1][0] = -3.3434;
  A.matrix[1][1] = 5.4543;

  s21_remove_matrix(&A);
  ck_assert_int_eq(err, 0);
}

void srunner_add_remove_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Remove");
  TCase *tc_remove = tcase_create("Remove");
  suite_add_tcase(save_v1, tc_remove);

  // Remove fun()
  tcase_add_test(tc_remove, s21_add_test_1);
  tcase_add_test(tc_remove, s21_add_test_2);
  tcase_add_test(tc_remove, s21_add_test_3);

  srunner_add_suite(sr, save_v1);
}