#include "s21_matrix_tests.h"

START_TEST(s21_add_test_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);
  int err = 0;
  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}

START_TEST(s21_add_test_3) {
  int err = 0;
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);

  matrix_1.matrix[0][0] = 5.0;
  matrix_1.matrix[0][1] = 4.0;
  matrix_1.matrix[0][2] = 3.0;
  matrix_1.matrix[0][3] = 2.0;
  matrix_1.matrix[0][4] = 1.0;
  matrix_1.matrix[1][0] = 1.0;
  matrix_1.matrix[1][1] = 2.0;
  matrix_1.matrix[1][2] = 3.0;
  matrix_1.matrix[1][3] = 4.0;
  matrix_1.matrix[1][4] = 5.0;
  matrix_1.matrix[2][0] = 2.0;
  matrix_1.matrix[2][1] = 1.0;
  matrix_1.matrix[2][2] = 3.0;
  matrix_1.matrix[2][3] = 3.0;
  matrix_1.matrix[2][4] = 5.0;
  matrix_1.matrix[3][0] = 3.0;
  matrix_1.matrix[3][1] = 2.0;
  matrix_1.matrix[3][2] = 4.0;
  matrix_1.matrix[3][3] = 1.0;
  matrix_1.matrix[3][4] = 5.0;
  matrix_1.matrix[4][0] = 5.0;
  matrix_1.matrix[4][1] = 3.0;
  matrix_1.matrix[4][2] = 1.0;
  matrix_1.matrix[4][3] = 2.0;
  matrix_1.matrix[4][4] = 4.0;

  matrix_2.matrix[0][0] = 5.0;
  matrix_2.matrix[0][1] = 4.0;
  matrix_2.matrix[0][2] = 3.0;
  matrix_2.matrix[0][3] = 2.0;
  matrix_2.matrix[0][4] = 1.0;
  matrix_2.matrix[1][0] = 1.0;
  matrix_2.matrix[1][1] = 2.0;
  matrix_2.matrix[1][2] = 3.0;
  matrix_2.matrix[1][3] = 4.0;
  matrix_2.matrix[1][4] = 5.0;
  matrix_2.matrix[2][0] = 2.0;
  matrix_2.matrix[2][1] = 1.0;
  matrix_2.matrix[2][2] = 3.0;
  matrix_2.matrix[2][3] = 3.0;
  matrix_2.matrix[2][4] = 5.0;
  matrix_2.matrix[3][0] = 3.0;
  matrix_2.matrix[3][1] = 2.0;
  matrix_2.matrix[3][2] = 4.0;
  matrix_2.matrix[3][3] = 1.0;
  matrix_2.matrix[3][4] = 5.0;
  matrix_2.matrix[4][0] = 5.0;
  matrix_2.matrix[4][1] = 3.0;
  matrix_2.matrix[4][2] = 1.0;
  matrix_2.matrix[4][3] = 2.0;
  matrix_2.matrix[4][4] = 4.0;

  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(1, err);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}

START_TEST(s21_add_test_4) {
  int err = 0;
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);

  matrix_1.matrix[0][0] = 5.0;
  matrix_1.matrix[0][1] = 4.0;
  matrix_1.matrix[0][2] = 3.0;
  matrix_1.matrix[1][0] = 1.0;
  matrix_1.matrix[1][1] = 2.0;
  matrix_1.matrix[1][2] = 3.0;
  matrix_1.matrix[2][0] = 2.0;
  matrix_1.matrix[2][1] = 1.0;
  matrix_1.matrix[2][2] = 3.0;

  matrix_2.matrix[0][0] = 5.0;
  matrix_2.matrix[0][1] = 4.0;
  matrix_2.matrix[0][2] = 3.0;
  matrix_2.matrix[1][0] = 1.0;
  matrix_2.matrix[1][1] = 2.56567;
  matrix_2.matrix[1][2] = 3.0;
  matrix_2.matrix[2][0] = 2.0;
  matrix_2.matrix[2][1] = 1.0;
  matrix_2.matrix[2][2] = 3.0;

  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(0, err);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}

START_TEST(s21_add_test_5) {
  int err = 0;
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(1, 5, &matrix_1);
  s21_create_matrix(1, 5, &matrix_2);

  matrix_1.matrix[0][0] = 5.0;
  matrix_1.matrix[0][1] = 4.0;
  matrix_1.matrix[0][2] = 3.0;
  matrix_1.matrix[0][0] = 1.0;
  matrix_1.matrix[0][1] = 5.64565;

  matrix_2.matrix[0][0] = 5.0;
  matrix_2.matrix[0][1] = 4.0;
  matrix_2.matrix[0][2] = 3.0;
  matrix_2.matrix[0][3] = 1.0;
  matrix_2.matrix[0][4] = 5.64;

  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(0, err);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}

START_TEST(s21_add_test_6) {
  int err = 0;
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);

  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(1, err);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}

START_TEST(s21_add_test_7) {
  int err = 0;
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);

  matrix_1.matrix[0][0] = 5.00000011;
  matrix_1.matrix[0][1] = 4.0;
  matrix_1.matrix[1][0] = 3.0;
  matrix_1.matrix[1][1] = 2.0;

  matrix_2.matrix[0][0] = 5.000000012;
  matrix_2.matrix[0][1] = 4.0;
  matrix_2.matrix[1][0] = 3.0;
  matrix_2.matrix[1][1] = 2.0;

  err = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(1, err);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}

START_TEST(s21_add_test_8) {
  matrix_t m1;
  matrix_t m2;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  m1.matrix[0][0] = 0.0;
  m1.matrix[0][1] = 1.0;
  m1.matrix[0][2] = 2.0;
  m1.matrix[1][0] = 3.0;
  m1.matrix[1][1] = 4.0;
  m1.matrix[1][2] = 5.0;
  m1.matrix[2][0] = 6.0;
  m1.matrix[2][1] = 7.0;
  m1.matrix[2][2] = 8.0;
  m2.matrix[0][0] = 0.0;
  m2.matrix[0][1] = 1.0;
  m2.matrix[0][2] = 2.0;
  m2.matrix[1][0] = 3.0;
  m2.matrix[1][1] = 4.0;
  m2.matrix[1][2] = 5.0;
  m2.matrix[2][0] = 6.0;
  m2.matrix[2][1] = 7.0;
  m2.matrix[2][2] = 8.0;
  int result = s21_eq_matrix(&m1, &m2);
  int result_origin = 1;
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(result, result_origin);
}

START_TEST(s21_add_test_9) {
  matrix_t m1;
  matrix_t m2;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  m1.matrix[0][0] = 987654321.123456789;
  m1.matrix[0][1] = 1111111111111.1111111111111;
  m1.matrix[0][2] = 2.0;
  m1.matrix[1][0] = 3.0000001;
  m1.matrix[1][1] = 4.111111111;
  m1.matrix[1][2] = 5123454321.5123454321;
  m1.matrix[2][0] = 666666666666.0;
  m1.matrix[2][1] = 7.0;
  m1.matrix[2][2] = 987654321.9123456789;
  m2.matrix[0][0] = 987654321.123456789;
  m2.matrix[0][1] = 1111111111111.1111111111111;
  m2.matrix[0][2] = 2.0;
  m2.matrix[1][0] = 3.0000001;
  m2.matrix[1][1] = 4.111111111;
  m2.matrix[1][2] = 5123454321.5123454321;
  m2.matrix[2][0] = 666666666666.0;
  m2.matrix[2][1] = 7.0;
  m2.matrix[2][2] = 987654321.9123456789;
  int result = s21_eq_matrix(&m1, &m2);
  int result_origin = 1;
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(result, result_origin);
}

START_TEST(s21_add_test_10) {
  matrix_t m1;
  matrix_t m2;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  m1.matrix[0][0] = 987654321.1234567;
  m1.matrix[0][1] = 1111111111111.1111111;
  m1.matrix[0][2] = 2.0000000;
  m1.matrix[1][0] = 3.0000001;
  m1.matrix[1][1] = 4.1111111;
  m1.matrix[1][2] = 5123454321.5123454;
  m1.matrix[2][0] = 666666666666.0000000;
  m1.matrix[2][1] = 7.0000000;
  m1.matrix[2][2] = 987654321.9123456;
  m2.matrix[0][0] = 987654321.1234567;
  m2.matrix[0][1] = 1111111111111.1111111;
  m2.matrix[0][2] = 2.0000000;
  m2.matrix[1][0] = 3.0000001;
  m2.matrix[1][1] = 4.1111111;
  m2.matrix[1][2] = 5123454321.5123454;
  m2.matrix[2][0] = 666666666666.0000000;
  m2.matrix[2][1] = 7.0000000;
  m2.matrix[2][2] = 987654321.9123456;
  int result = s21_eq_matrix(&m1, &m2);
  int result_origin = 1;
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(result, result_origin);
}

START_TEST(s21_add_test_11) {
  matrix_t m1;
  matrix_t m2;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  m1.matrix[0][0] = 987654321.1234567;
  m1.matrix[0][1] = 1111111111111.111111;
  m1.matrix[0][2] = 2.0000005;
  m1.matrix[1][0] = 3.0000001;
  m1.matrix[1][1] = 4.1111111;
  m1.matrix[1][2] = 5123454321.5123454;
  m1.matrix[2][0] = 666666666666.0;
  m1.matrix[2][1] = 7.0;
  m1.matrix[2][2] = 987654321.9123456;
  m2.matrix[0][0] = 987654321.1234567;
  m2.matrix[0][1] = 1111111111111.111111;
  m2.matrix[0][2] = 2.0;
  m2.matrix[1][0] = 3.0000001;
  m2.matrix[1][1] = 4.1111111;
  m2.matrix[1][2] = 5123454321.5123454;
  m2.matrix[2][0] = 666666666666.0;
  m2.matrix[2][1] = 7.0;
  m2.matrix[2][2] = 987654321.9123456;
  int result = s21_eq_matrix(&m1, &m2);
  int result_origin = 0;
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(result, result_origin);
}

START_TEST(s21_add_test_12) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.33333356;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = -3;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 3.33333356;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -3;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_add_test_13) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.33333357;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = -3;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 3.33333356;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -3;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_add_test_14) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.0;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = -3;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 2.0;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -3;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_add_test_15) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.3333333;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3.3333334;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 3.3333333;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 3.3333335;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_add_test_16) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t B;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_add_test_17) {
  matrix_t A;
  s21_create_matrix(-1, 1, &A);
  matrix_t B;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&B);
}

START_TEST(s21_add_test_18) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  matrix_t B;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_add_test_19) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.33333356;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = -3;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 3.33333356;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -3;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_add_test_20) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.33333357;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = -3;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 3.33333356;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -3;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_add_test_21) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.0;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = -3;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 2.0;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = -3;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_add_test_22) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.3333333;
  A.matrix[0][1] = -5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3.3333334;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 3.3333333;
  B.matrix[0][1] = -5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 3.3333335;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_add_test_23) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t B;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_add_test_24) {
  matrix_t A;
  s21_create_matrix(-1, 1, &A);
  matrix_t B;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_add_test_25) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  matrix_t B;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

void srunner_add_equal_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Equal");
  TCase *tc_equal = tcase_create("Equal");
  suite_add_tcase(save_v1, tc_equal);

  // Equal fun()
  tcase_add_test(tc_equal, s21_add_test_1);
  tcase_add_test(tc_equal, s21_add_test_3);
  tcase_add_test(tc_equal, s21_add_test_4);
  tcase_add_test(tc_equal, s21_add_test_5);
  tcase_add_test(tc_equal, s21_add_test_6);
  tcase_add_test(tc_equal, s21_add_test_7);
  tcase_add_test(tc_equal, s21_add_test_8);
  tcase_add_test(tc_equal, s21_add_test_9);
  tcase_add_test(tc_equal, s21_add_test_10);
  tcase_add_test(tc_equal, s21_add_test_11);
  tcase_add_test(tc_equal, s21_add_test_12);
  tcase_add_test(tc_equal, s21_add_test_13);
  tcase_add_test(tc_equal, s21_add_test_14);
  tcase_add_test(tc_equal, s21_add_test_15);
  tcase_add_test(tc_equal, s21_add_test_16);
  tcase_add_test(tc_equal, s21_add_test_17);
  tcase_add_test(tc_equal, s21_add_test_18);
  tcase_add_test(tc_equal, s21_add_test_19);
  tcase_add_test(tc_equal, s21_add_test_20);
  tcase_add_test(tc_equal, s21_add_test_21);
  tcase_add_test(tc_equal, s21_add_test_22);
  tcase_add_test(tc_equal, s21_add_test_23);
  tcase_add_test(tc_equal, s21_add_test_24);
  tcase_add_test(tc_equal, s21_add_test_25);

  srunner_add_suite(sr, save_v1);
}