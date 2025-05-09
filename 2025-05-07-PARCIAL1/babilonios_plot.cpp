#include <iostream>
#include <fstream>
#include <cmath>

// declaration

int main(int argc, char **argv) {
    double s_given = 234.56789;

    // open file for writing
    std::ofstream file("babilonian_root.txt");

    std::cout.precision(12);
    std::cout.setf(std::ios::scientific);

    double r = 1.0;
    double r1 = 1.0;
    long counter = 0;
    double exact_result = std::sqrt(s_given);
    long n = 0;

    for (n = 0 ;n <= 10; n++){
    for (r = 1.0; ;){
        if (n == 1){
            r = 1.0;
        }
        if (n > 1){
        r = (r1 + s_given/r1)/2.0;
        r = r1;
        counter ++;
        if (counter == n){
            std::cout << r <<  "\n";
            double root_error = std::abs(1.0 - r1/exact_result);
            file << s_given << " " 
                << root_error << " "
                << n << " "
                << std::endl;
            break;
        }
        }
    }
    
    }
    
    file.close();
    return 0;
}
