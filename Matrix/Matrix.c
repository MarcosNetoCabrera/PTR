//
// Created by vinic on 28/06/2022.
//
#include "stdio.h"
#include "stdlib.h"
#include "Matrix.h"

Matrix matrix_null = {.lines=0, .columns=0, .values=NULL};
#define VALUES(m, i, j) (m.values[i * m.columns + j])


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

Matrix matrix_radom(unsigned int lines, unsigned int columns){
    Matrix matrix = matrix_constructor(lines,columns);
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            matrix.values[i*matrix.columns+j] = rand() % 10;
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
        Matrix matrix_result = matrix_constructor(matrix_1.lines,matrix_1.columns);
    if(matrix_1.columns == matrix_2.columns && matrix_1.lines == matrix_2.lines){
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

Matrix matrix_mult(Matrix matrix_A, Matrix matrix_B){
    if(matrix_A.columns == matrix_B.lines){
        Matrix matrix_result = matrix_constructor(matrix_A.lines,matrix_B.columns);
        for (int i = 0; i < matrix_A.lines; i++){
            for(int j = 0;j < matrix_B.columns; j++){
                double soma = 0;
                for (int k = 0; k < matrix_B.lines; k++) {
                    soma += matrix_A.values[i*matrix_A.columns + k] * matrix_B.values[k*matrix_B.columns + j];
                }
                matrix_result.values[i*matrix_result.columns+j] = soma;
            }
        }
        return matrix_result;
    }else{
        printf("ERRO: O numero de colunas da matriz A deve ser igual ao número de linhas da matriz B");
        return matrix_null;
    }
}

void matrix_print(Matrix matrix){
    if(matrix.values != NULL){
        printf("Matrix : (%d,%d)  \n",matrix.lines,matrix.columns);
        for(int i  = 0; i < matrix.lines; i++){
            printf("[ ");
            for(int j = 0; j < matrix.columns; j++){
                printf("%0.5f ",matrix.values[i*matrix.columns+j]);
            }
            printf("]\n");
        }
    }else{
        printf("Matriz sem valores top essa aq kkkk\n");
    };
}
int find_index_0(Matrix m){
    for(int i=0;i<m.lines;i++){
        for(int j=0;j<m.columns;i++){
            return m.values[0];
        }
    }
}

double matrix_det(Matrix matrix){
    if(matrix.columns != matrix.lines){
        printf("ERRO: A matrix deve ter o mesmo numero de linhas e colunas\n");
        return -1;
    }else if(matrix.columns == 1){
        return matrix.values[0];
    }else if(matrix.lines == 2){
        return matrix.values[0]*matrix.values[3] - matrix.values[1]*matrix.values[2];
    }else{
        Matrix menor = matrix_constructor(matrix.lines-1,matrix.columns-1);
        int linha,coluna;
        int nLinhas_menor,nColunas_menor;
        double soma=0;
        int index;

        for(index = 0; index < matrix.lines;index++) {

            nLinhas_menor = 0;

            for (linha = 1; linha < matrix.lines; linha++) {

                nColunas_menor = 0;

                for (coluna = 0; coluna < matrix.columns; coluna++) {
                    if (coluna == index) {
                        continue;
                    } else {
                        VALUES(menor, nLinhas_menor, nColunas_menor) = VALUES(matrix, linha, coluna);
                    }
                    nColunas_menor++;
                }
                nLinhas_menor++;
            }

            if (index % 2 == 0) {
                soma += VALUES(matrix, 0, index) * matrix_det(menor);
            } else {
                soma -= VALUES(matrix, 0, index) * matrix_det(menor);
            }
        }
        return soma;
    }
}
double matrix_det_gauss(Matrix matrix){
    double ratio, det=1;
    int num = matrix.lines;

    if (matrix.lines!=matrix.columns){
        printf("ERRO: A matrix deve ter o mesmo numero de linhas e colunas\n");
        exit(0);
    }
    for(int i=0;i<num;i++){
        if(VALUES(matrix,i,i)==0){
            printf("ERRO: operacao invalida");
            exit(0);
        }
        for (int j = i+1; j < num; ++j) {

            ratio = VALUES(matrix,j,i)/ VALUES(matrix,i,i);

            for(int k=0; k < num ;k++){
                VALUES(matrix,j,k) = VALUES(matrix,j,k) - ratio*VALUES(matrix,i,k);
            }
        }
    }
    for(int i=0;i<num;i++){
        det = det * VALUES(matrix,i,i);
    }
    return det;
}
Matrix matrix_inverse(Matrix matrix){
    Matrix identidade = matrix_identify(matrix.lines,matrix.columns);
    int tam = matrix.lines;
    double temp=0;
    for(int k = 0; k < tam;k++){
        temp = VALUES(matrix,k,k);
        for(int j = 0;j < tam;j++){
            VALUES(matrix,k,j)/=temp;
            VALUES(identidade,k,j)/=temp;
        }
        for(int i=0;i<tam;i++){
            temp = VALUES(matrix,i,k);
            for(int j=0; j < tam;j++){
                if(i==k) break;

                VALUES(matrix,i,j) -= VALUES(matrix,k,j) * temp;
                VALUES(identidade,i,j) -= VALUES(identidade,k,j) * temp;
            }
        }
    }
    return identidade;
}


void matrix_free(Matrix *m){
    if(m) {
        free(m->values);
        *m = matrix_null;
    }
}

