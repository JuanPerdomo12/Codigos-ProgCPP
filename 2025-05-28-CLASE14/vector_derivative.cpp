#include <vector>
#include <iostream>
#include <string>
#include <cmath>

std::vector<double> deriv(const std::vector<double> & val){
    std::vector<double> derivada;
    for (int i = 1; i<val.size() ; i++){
        derivada.push_back(i * val[i]);
    }
    return derivada;
}

double evaderiv(const std::vector<double> & val2, double & x){
    double result = 0.0;
    for(int i = 0; i < val2.size(); ++i) {
        result += val2[i] * std::pow(x, i);
    }
    return result;
}

int main(void) {
    
    std::vector<double> data = {1, 3, 4.5};
    
    std::vector<double> newdata = deriv(data);
    
    for (double coeff : data) {
        std::cout << coeff << " ";
    }
    std::cout << std::endl;
    
    for (double coeff : newdata) {
        std::cout << coeff << " ";
    }
    std::cout << std::endl;

    double x = 4.0;

    std::cout << evaderiv(newdata, x) << "\n";

    return 0;
}