#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Integral.h"
#include "Matrix.h"

#define delta 0.0001

double exponecial2(double input){
    return input*input;
}

double funcao_identidade(double input){
    return input;
}

double funcao_grau2(double input){
    return (2*input*input)+4*input+4;
}
int main() {
    
    printf("******************** FUNCOES MATRIX ********************\n\n");

    printf("Criando uma matrix com valores aleatorios 4x4 \n");
    Matrix matrix = matrix_random(4,4);
    matrix_print(matrix);
    printf("\n");
    printf("Criando uma matrix de zeros 4x4 \n");
    matrix = matrix_zeros(4,4);
    matrix_print(matrix);
    printf("\n");
    printf("Criando uma matrix de uns 4x4 \n");
    matrix = matrix_ones(4,4);
    matrix_print(matrix);
    printf("\n");
    printf("Criando uma matrix de identidade 4x4 \n");
    matrix = matrix_identify(4,4);
    matrix_print(matrix);
    printf("\n");
    printf("Utilizando a funcao de soma escalar para somar a matriz de uns mais o escalar 2 \n");
    matrix = matrix_ones(4,4);
    matrix = matrix_sum_scalar(matrix,2);
    matrix_print(matrix);
    printf("\n");
    printf("Utilizando a funcao de subtracao por escalar para subtrair pelo escalar 2 da matriz de uns \n");
    matrix = matrix_ones(4,4);
    matrix = matrix_sub_scalar(matrix,2);
    matrix_print(matrix);
    printf("\n");
    printf("Utilizando a funcao de multiplicacao por escalar para multiplicar a matriz de uns por 5 \n");
    matrix = matrix_ones(4,4);
    matrix = matrix_mult_scalar(matrix,5);
    matrix_print(matrix);
    printf("\n");
    
    printf("Utilizando a funcao de soma entre duas matrizes 4x4 \n");
    printf("\nMatrix 1\n");
    matrix = matrix_ones(4,4);
    matrix_print(matrix);
    Matrix matrix2 = matrix_random(4,4);
    printf("\nMatrix 2\n");
    matrix_print(matrix2);
    matrix = matrix_sum(matrix,matrix2);
    printf("\nResultado da soma\n");
    matrix_print(matrix);
    printf("\n");
    
    printf("Utilizando a funcao de subtracao entre matrizes 4x4 \n");
    printf("\nMatrix 1\n");
    matrix = matrix_random(4,4);
    matrix_print(matrix);
    matrix2 = matrix_ones(4,4);
    printf("\nMatrix 2\n");
    matrix_print(matrix2);
    matrix = matrix_sub(matrix,matrix2);
    printf("\nResultado da subtracao\n");
    matrix_print(matrix);
    printf("\n");

    printf("Utilizando a funcao de multiplicacao entre duas matrizes 4x4 \n");
    printf("\nMatrix 1\n");
    matrix = matrix_random(4,4);
    matrix_print(matrix);
    matrix2 = matrix_random(4,4);
    printf("\nMatrix 2\n");
    matrix_print(matrix2);
    matrix = matrix_mult(matrix,matrix2);
    printf("\nResultado da multiplicacao\n");
    matrix_print(matrix);
    printf("\n");

    printf("Utilizando a funcao que retorna uma matrix transposta \n");
    printf("\nMatriz Original\n");
    matrix = matrix_random(4,4);
    matrix_print(matrix);
    printf("\nMatriz transposta\n");
    matrix = matrix_transpose(matrix);
    matrix_print(matrix);
    printf("\n");

    printf("Utilizando a funcao que retorna o determinante de uma matrix temos \n");
    printf("\nMatriz Original\n");
    matrix = matrix_random(4,4);
    double valor = matrix_det(matrix);
    matrix_print(matrix);
    printf("\nDeterminante: %.5f\n",valor);
    printf("\n");

    printf("Utilizando a funcao que dado uma matriz retorna sua inversa \n");
    printf("\nMatriz Original\n");
    matrix = matrix_random(4,4);
    matrix_print(matrix);
    printf("\nMatriz Inversa\n");
    matrix = matrix_inverse(matrix);
    matrix_print(matrix);
    printf("\n");

    printf("Funcao para criar matrizes com os valores desejados \n");
    double matrix3 [][2] = {{2,4},{3,6}};
    matrix = matrix_create(2,2,matrix3,4);
    matrix_print(matrix);
    printf("\n");


    printf("******************** FUNCOES INTEGRAL ********************\n\n");
    printf("Funcao f(x) = x*x\n");
    printf("liminte inferior: 0\nlimite superior: 3\ndelta: %f\n",delta);
    printf("Resultado dos metodos implementado\n");
    double result = integral_trapezio(delta,0,3, exponecial2);
    double result2 = integral_simpson(delta,0,3,exponecial2);
    printf("Resultado Regra do Trapezio: %f\n",result);
    printf("Resultado Regra do Simpson: %f\n",result2);


    printf("\nFuncao f(x) = x\n");
    printf("liminte inferior: 2\nlimite superior: 8\ndelta: %f\n",delta);
    printf("Resultado dos metodos implementado\n");
    result = integral_trapezio(delta,2,8, funcao_identidade);
    result2 = integral_simpson(delta,2,8, funcao_identidade);
    printf("Resultado Regra do Trapezio: %f\n",result);
    printf("Resultado Regra do Simpson: %f\n",result2);


    printf("\nFuncao f(x) = 2x*x+4x+4\n");
    printf("liminte inferior: 10\nlimite superior: 31\ndelta: %f\n",delta);
    printf("Resultado dos metodos implementado\n");
    result = integral_trapezio(delta,10,31, funcao_grau2);
    result2 = integral_simpson(delta,10,31, funcao_grau2);
    printf("Resultado Regra do Trapezio: %f\n",result);
    printf("Resultado Regra do Simpson: %f\n",result2);
    

    matrix_free(&matrix);
    //matrix_free(&m);
    return 0;
}