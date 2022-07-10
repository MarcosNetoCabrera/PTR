#include <stdio.h>
#include "Matrix.h"

int main() {
    Matrix  matrix = matrix_radom(6,6);

    //Matrix  matrix2 = matrix_radom(3,3);

    //matrix_print(matrix2);
    //Matrix matrix3 = matrix_mult(matrix,matrix2);

    matrix_print(matrix);

    Matrix m = matrix_inverse(matrix);
    matrix_print(m);

    //double res = matrix_det(matrix);
    //printf("\ndet: %0.1f",res);


    //matrix_print(matrix2);
    //matrix_print(matrix3);



    matrix_free(&matrix);
    //matrix_free(&matrix2);
    //matrix_free(&matrix2);

    return 0;
}
