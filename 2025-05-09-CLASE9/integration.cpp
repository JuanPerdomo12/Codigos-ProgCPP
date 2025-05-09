#include "integration.h"

//Implementation
double trapezoid(double a, double b, int N, fptr f){
    double deltax = (b - a)/N;
    double sum = 0.0;

    for (int k = 1; k <= N-1; k++){
        double x_k = a + k * deltax;
        sum = sum + f(x_k);
    }
    double result = deltax * (0.5 * f(a) + sum + 0.5 * f(b));
    return result;
}

double simpson(double a, double b, int N, fptr f){
    double deltax = (b - a)/N;
    double sum1 = 0.0;
    double sum2 = 0.0;

    for (int k = 1; k <= N * 0.5; k++){
        double x_2k1 = a + 2 * k * deltax - 1;
        sum1 = sum1 + f(x_2k1);
    }

    for (int k = 1; k <= N * 0.5 - 1; k++){
        double x_2k = a + 2 * k * deltax;
        sum2 = sum2 + f(x_2k);
    }
    double result = deltax * (1/3) * (f(a) + 4 * sum1 + 2 * sum2 + f(b));
    return result;
}