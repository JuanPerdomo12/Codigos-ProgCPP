#include "derivates_utils.h"

//Implementation
double forward_diff(double x, double h, fptr f){
    return (f(x + h) - f(x))/h;
}
double central_diff(double x, double h, fptr f){
    return (f(x + h) - f(x - h))/2*h;
}