#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>

//Declaration
using fptr = std::function<double(double)>;

double trapezoid(double a, double b, int N, fptr f);
double simpson(double, double b, int N, fptr f);

using algptr = std::function<double(double, double, int, fptr)>;

double richardson(double a, double b, int N, fptr f, algptr alg, int alpha);

double gauss2(double a, double b, fptr f);

double gauss3(double a, double b, fptr f);

//function
double f(double x);

int main(void){
    double exact_result = 2.0/3.0;


    // open file for writing
    std::ofstream file("integration_all.txt");
    file.precision(15);
    file.setf(std::ios::scientific);

    for (int N = 2; N <= 10; N++){
    double trapezoid_result = trapezoid(-2.0, 2.0, N, f);
    double simpson_result = simpson(-2.0, 2.0, N, f);
    double richardson_trapezoid_result = richardson(-2.0, 2.0, N, f, trapezoid, 2);
    double richardson_simpson_result = richardson(-2.0, 2.0, N, f, simpson, 4);
    double error_trapezoid = std::abs(1.0 - trapezoid_result/exact_result);
    double error_simpson = std::abs(1.0 - simpson_result/exact_result);
    double error_richardson_trapezoid = std::abs(1.0 - richardson_trapezoid_result/exact_result);
    double error_richardson_simpson = std::abs(1.0 - richardson_simpson_result/exact_result);
    double gauss_quadrature2 = gauss2(-2.0, 2.0, f);
    double error_gauss2 = std::abs(1.0 - gauss_quadrature2/exact_result);
    double gauss_quadrature3 = gauss3(-2.0, 2.0, f);
    double error_gauss3 = std::abs(1.0 - gauss_quadrature3/exact_result);
    file << N << " "
            << trapezoid_result << " "
            << error_trapezoid << " "
            << richardson_trapezoid_result << " "
            << error_richardson_trapezoid << " "
            << simpson_result << " "
            << error_simpson << " "
            << richardson_simpson_result << " "
            << error_richardson_simpson << " "
            << gauss_quadrature2 << " "
            << error_gauss2 << " "
            << gauss_quadrature3 << " "
            << error_gauss3 <<
            std::endl;
    }
    file.close();
    return 0;
}

double f( double x){
    return 7*x*x*x - 8*x*x + 3*x + 3;
}

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
    if (N % 2 != 0){
        N ++;
    }

    double deltax = (b - a)/N;
    double sum1 = 0.0;
    double sum2 = 0.0;

    for (int k = 1; k <= N * 0.5; k++){
        double x_2k1 = a + (2 * k - 1) * deltax;
        sum1 = sum1 + f(x_2k1);
    }

    for (int k = 1; k <= N * 0.5 - 1; k++){
        double x_2k = a + 2 * k * deltax;
        sum2 = sum2 + f(x_2k);
    }
    double result = deltax * (1.0/3.0) * (f(a) + 4 * sum1 + 2 * sum2 + f(b));
    return result;
}

double richardson(double a, double b, int N, fptr f, algptr alg, int alpha){
    double aux = std::pow(2.0, alpha);
    double R1 = alg(a, b, N, f);
    double R2 = alg(a, b, N * 2, f);
    double result = (aux * R2 - R1) / (aux - 1.0);
    return result;
}

double gauss2(double a, double b, fptr f){
    //define point coordinates
    double x0 = -1.0/std::sqrt(3.0);
    double x1 = +1.0/std::sqrt(3.0);

    //define weights
    double w0 = 1.0;
    double w1 = 1.0;

    //capture integral
    double result = (b - a)/2.0 * (w0 * f(((b - a) * x0)/2.0 + (a + b)/2.0) + w1 * f(((b - a) * x1)/2.0 + (a + b)/2.0));
    return result;
}

double gauss3(double a, double b, fptr f){
    //define point coordinates
    double x0 = -std::sqrt(3.0/5.0);
    double x1 = 0.0;
    double x2 = +std::sqrt(3.0/5.0);

    //define weights
    double w0 = 5.0/9.0;
    double w1 = 8.0/9.0;
    double w2 = 5.0/9.0;

    //capture integral
    double result = (b - a)/2.0 * (w0 * f(((b - a) * x0)/2.0 + (a + b)/2.0) + w1 * f(((b - a) * x1)/2.0 + (a + b)/2.0) 
    + w2 * f(((b - a) * x2)/2.0 + (a + b)/2.0));
    return result;
}