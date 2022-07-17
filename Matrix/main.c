#include <stdio.h>
#include "Matrix.h"

int main() {
    /*
    Matrix  matrix = matrix_random(6,6);

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
    */

    double values[2][3] = {{1.2,2.3, 5.3},{3.1,5.3,1.1}};
    int lines = 2;
    int columns = 3;
    int len = (sizeof (values)/sizeof (double ));

    Matrix  matrix = matrix_create(lines,columns,values,len);
    matrix_print(matrix);
    return 0;
}
