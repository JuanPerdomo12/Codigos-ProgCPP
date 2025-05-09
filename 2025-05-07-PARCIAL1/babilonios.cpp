#include <iostream>
#include <cmath>

int main(int argc, char **argv) {
    double s_given = std::stod(argv[1]);
    long n_given = std::stol(argv[2]);

    std::cout.precision(12);
    std::cout.setf(std::ios::scientific);

    double r = 1.0; //mi variable r (raiz) arranca en 1.0

    for (int n = 1.0; n < n_given; n++){ //declaro mi contador como variable dentro del for
        r = (r + s_given/r)/2.0;
        }
    std::cout << r <<  "\n";
    return 0;
}

