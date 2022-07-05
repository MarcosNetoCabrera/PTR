#include <stdio.h>
#include "Matrix.h"

int main() {
    Matrix  matrix = matrix_identify(3,3);
    Matrix  matrix2 = matrix_ones(3,3);
    Matrix  matrix_result = matrix_sub(matrix,matrix2);
    Matrix matrix3 = matrix_mult_scalar(matrix,2);
    matrix3 = matrix_sum_scalar(matrix3,3);
    Matrix matrix_trp = matrix_transpose(matrix3);
    //matrix_print(matrix);
    //matrix_print(matrix2);
    matrix_print(matrix3);
    printf("\n");
    matrix_print(matrix_trp);

    return 0;

}
