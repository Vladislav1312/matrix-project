#ifndef S21_MATRIX_TESTS_H_
#define S21_MATRIX_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

void srunner_add_create_tests(SRunner *sr);       //+
void srunner_add_remove_tests(SRunner *sr);       //+
void srunner_add_equal_tests(SRunner *sr);        //+
void srunner_add_sum_tests(SRunner *sr);          //+
void srunner_add_sub_tests(SRunner *sr);          //+
void srunner_add_mult_number_tests(SRunner *sr);  //+
void srunner_add_mult_tests(SRunner *sr);         //+
void srunner_add_transpose_tests(SRunner *sr);    //+
void srunner_add_calc_tests(SRunner *sr);         //+
void srunner_add_determinant_tests(SRunner *sr);  //+
void srunner_add_inverse_tests(SRunner *sr);      //+

#endif