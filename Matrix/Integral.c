//
// Created by vinic on 17/07/2022.
//
#include "stdio.h"
#include "Integral.h"



double integral_trapezio(double delta,double limit_inferior, double limit_superior, PtrFunction funcao){
    double result = 0;

    for(double i = limit_inferior; i < limit_superior; i+=delta){
        result += delta*(funcao(i+delta)+funcao(i))/2;
    }

    return result;
}

double integral_simpson(double delta, double limit_inferior, double limit_superior, PtrFunction funcao){
    double result = 0;

    for(double i = limit_inferior; i < limit_superior; i+= delta){
        result += ((delta)/6)*(funcao(i)+4*funcao((2*i+delta)/2) + funcao(i+delta));
    }

    return result;
}