#include "s21_matrix_tests.h"

int main() {
  Suite *s = suite_create("Matrix tests");
  SRunner *sr = srunner_create(s);
  int err;

  srunner_add_create_tests(sr);
  srunner_add_remove_tests(sr);
  srunner_add_equal_tests(sr);
  srunner_add_sum_tests(sr);
  srunner_add_sub_tests(sr);
  srunner_add_mult_number_tests(sr);
  srunner_add_mult_tests(sr);
  srunner_add_transpose_tests(sr);
  srunner_add_calc_tests(sr);
  srunner_add_determinant_tests(sr);
  srunner_add_inverse_tests(sr);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);  // CK_ENV?
  err = srunner_ntests_failed(sr);
  srunner_free(sr);

  return err == 0 ? 0 : 1;
}