#include <stdio.h>
#include "Integral.h"

#define delta 0.0001

double exponecial3(double input){
    return input*input*input;
}

int main() {
    printf("Hello, World!\n");
    double result = integral_trapezio(delta,0,4, exponecial3);
    double result2 = integral_simpson(delta,0,4,exponecial3);
    printf("Resultado Regra do Trapezio: %f\n",result);
    printf("Resultado Regra do Simpson: %f\n",result2);
    return 0;
}
