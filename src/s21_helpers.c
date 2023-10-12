#include "s21_matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void s21_print_matrix(matrix_t *A) {
  if(A -> matrix){
    for (int i = 0; i < A -> rows; i++) {
      for (int j = 0; j < A -> columns; j++) {
        printf(" %3.7lf", A -> matrix[i][j]);
      }
      printf("\n");
    }
  }
}

void s21_add_value_matrix(matrix_t *A){
  if(A -> matrix){
    srand(time(NULL));
    for(int i = 0; i < A -> rows; i++){
      for(int j = 0; j < A -> columns; j++){
        double random_number = ((double)rand() / RAND_MAX) * 20.000000 - 10.000000;
        A -> matrix[i][j] = random_number;
      }
    }
  }
}