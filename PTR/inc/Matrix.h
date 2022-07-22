
typedef struct Matrix Matrix;
struct Matrix{
    unsigned int lines;
    unsigned int columns;
    double *values;
};
//Matrix matrix_null;
Matrix matrix_constructor(unsigned int lines, unsigned int columns);
Matrix matrix_random(unsigned int lines, unsigned int columns);
Matrix matrix_zeros(unsigned int lines, unsigned int columns);
Matrix matrix_ones(unsigned int lines, unsigned int columns);
Matrix matrix_identify(unsigned int lines, unsigned int columns);
Matrix matrix_sum(Matrix matrix_1,Matrix matrix_2);
Matrix matrix_sub(Matrix matrix_1,Matrix matrix_2);
Matrix matrix_sum_scalar(Matrix matrix, double scalar);
Matrix matrix_sub_scalar(Matrix matrix, double scalar);
Matrix matrix_transpose(Matrix matrix);
Matrix matrix_mult_scalar(Matrix matrix, double scalar);
double matrix_det_gauss(Matrix matrix);
Matrix matrix_inverse(Matrix matrix);
Matrix matrix_mult(Matrix matrix_A, Matrix matrix_B);
double matrix_det(Matrix matrix);
void matrix_free(Matrix *m);
void matrix_print(Matrix matrix);
Matrix matrix_create(int lines, int columns, double values[][columns], int len);