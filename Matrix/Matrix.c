//
// Created by vinic on 28/06/2022.
//
#include "stdio.h"
#include "stdlib.h"
#include "Matrix.h"


Matrix matrix_constructor(unsigned int lines, unsigned int columns){
    Matrix  matrix;
    matrix.columns = columns;
    matrix.lines = lines;
    matrix.values = malloc(lines*columns*sizeof (double));
    return matrix;
}

Matrix matrix_zeros(unsigned int lines, unsigned int columns){
    Matrix matrix = matrix_constructor(lines,columns);
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            matrix.values[i*matrix.columns+j] = 0;
        }
    }
    return matrix;
}

Matrix matrix_ones(unsigned int lines, unsigned int columns){
    Matrix matrix = matrix_constructor(lines,columns);
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            matrix.values[i*matrix.columns+j] = 1;
        }
    }
    return matrix;
}

Matrix matrix_identify(unsigned int lines, unsigned int columns){
    Matrix matrix = matrix_zeros(lines,columns);
    int min_way;
    if(lines>columns){
        min_way = columns;
    }else{
        min_way  =  lines;
    }
    for(int i = 0; i < min_way;i++){
        matrix.values[i*matrix.columns+i] = 1;
    }
    return  matrix;
}
Matrix matrix_sum(Matrix matrix_1,Matrix matrix_2){

    if(matrix_1.columns == matrix_2.columns && matrix_1.lines == matrix_2.lines){
        Matrix matrix_result = matrix_constructor(matrix_1.lines,matrix_1.columns);
        for(int i = 0; i < matrix_1.lines;i++){
            for(int j = 0; j < matrix_1.columns; j++){
                matrix_result.values[i*matrix_1.columns+j] = matrix_1.values[i*matrix_1.columns+j] + matrix_2.values[i*matrix_1.columns+j];
            }
        }
        return matrix_result;
    }else{
        Matrix matrix_result = matrix_constructor(0,0);
        matrix_result.values = NULL;
        printf("ERRO: As matrizes passadas possuem dimensioes distintas\n");
        return matrix_result;
    }
}

Matrix matrix_sum_scalar(Matrix matrix, double scalar){
    Matrix new_matrix = matrix_constructor(matrix.lines,matrix.columns);
    if(matrix.values != NULL){
        for(int i  = 0; i < matrix.lines*matrix.columns; i++){
            new_matrix.values[i] = matrix.values[i] + scalar;
        }
        return new_matrix;
    }else{
        new_matrix.values = NULL;
        return new_matrix;
    }
}

Matrix matrix_sub_scalar(Matrix matrix, double scalar){
    Matrix new_matrix = matrix_constructor(matrix.lines,matrix.columns);
    if(matrix.values != NULL){
        for(int i  = 0; i < matrix.lines*matrix.columns; i++){
            new_matrix.values[i] = matrix.values[i] - scalar;
        }
        return new_matrix;
    }else{
        new_matrix.values = NULL;
        return new_matrix;
    }
}

Matrix matrix_mult_scalar(Matrix matrix, double scalar){
    Matrix new_matrix = matrix_constructor(matrix.lines,matrix.columns);
    if(matrix.values != NULL){
        for(int i  = 0; i < matrix.lines*matrix.columns; i++){
            new_matrix.values[i] = matrix.values[i] * scalar;
        }
        return new_matrix;
    }else{
        new_matrix.values = NULL;
        return new_matrix;
    }
}
Matrix matrix_transpose(Matrix matrix){
    Matrix matrix_trp = matrix_constructor(matrix.columns,matrix.lines);
    if(matrix.values != NULL){
        for(int i = 0; i < matrix.lines; i++){
            for(int j = 0; j < matrix.columns; j++){
                matrix_trp.values[j*matrix.lines+i] = matrix.values[i*matrix.columns+j];
            }
        }
        return matrix_trp;
    }else{
        matrix_trp.values = NULL;
        return matrix_trp;
    }
}

Matrix matrix_sub(Matrix matrix_1,Matrix matrix_2){

    if(matrix_1.columns == matrix_2.columns && matrix_1.lines == matrix_2.lines){
        Matrix matrix_result = matrix_constructor(matrix_1.lines,matrix_1.columns);
        for(int i = 0; i < matrix_1.lines;i++){
            for(int j = 0; j < matrix_1.columns; j++){
                matrix_result.values[i*matrix_1.columns+j] = matrix_1.values[i*matrix_1.columns+j] - matrix_2.values[i*matrix_1.columns+j];
            }
        }
        return matrix_result;
    }else{
        Matrix matrix_result = matrix_constructor(0,0);
        matrix_result.values = NULL;
        printf("ERRO: As matrizes passadas possuem dimensioes distintas\n");
        return matrix_result;
    }
}

void matrix_print(Matrix matrix){
    if(matrix.values != NULL){
        for(int i  = 0; i < matrix.lines; i++){
            printf("[ ");
            for(int j = 0; j < matrix.columns; j++){
                printf("%f ",matrix.values[i*matrix.columns+j]);
            }
            printf("]\n");
        }
    }else{
        printf("Matriz sem valores top essa aq\n");
    };
}

