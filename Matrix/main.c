#include <stdio.h>
#include "Matrix.h"

int main() {
    Matrix  matrix = matrix_identify(3,3);
    Matrix  matrix2 = matrix_ones(3,3);
    Matrix  matrix_result = matrix_sub(matrix,matrix2);
    //matrix_print(matrix);
    //matrix_print(matrix2);
    matrix_print(matrix_result);
    matrix_print(matrix_result);
    return 0;

}
