#include <iostream> 
#include <valarray>
#include <cmath>
#include <iomanip>
#include <numeric>

void print(std::string msg, const std::valarray<double>& v)
{
    std::cout << msg << " ";
    for (auto n: v) { std::cout << std::setw(3) << n << " "; }
    std::cout << '\n';
}

int main(void){
    std::valarray<double> v1(1000);
    std::iota(std::begin(v1), std::end(v1), 0.0); 

    std::valarray<double> v2(1000);
    v2 = v1*2*(M_PI)/1000;

    std::valarray<double> v3 = sin(v2);
    std::valarray<double> v4 = v3[abs(v3) <= 0.5];

    print("Sin values less than or equal to 0.5:", v4);

    return 0;
}