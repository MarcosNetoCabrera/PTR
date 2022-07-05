
typedef struct Matrix Matrix;

struct  Matrix{
    unsigned int lines;
    unsigned int columns;
    double *values;
};

Matrix matrix_constructor(unsigned int lines, unsigned int columns);
Matrix matrix_zeros(unsigned int lines, unsigned int columns);
Matrix matrix_ones(unsigned int lines, unsigned int columns);
Matrix matrix_identify(unsigned int lines, unsigned int columns);
Matrix matrix_sum(Matrix matrix_1,Matrix matrix_2);
Matrix matrix_sub(Matrix matrix_1,Matrix matrix_2);
Matrix matrix_sum_scalar(Matrix matrix, double scalar);
Matrix matrix_sub_scalar(Matrix matrix, double scalar);
Matrix matrix_transpose(Matrix matrix);
Matrix matrix_mult_scalar(Matrix matrix, double scalar);
void matrix_print(Matrix matrix);