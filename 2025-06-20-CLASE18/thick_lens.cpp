#include <iostream>
#include <string>
#include <eigen3/Eigen/Dense>

Eigen::Matrix<double, 2, 2> operator_A(double R1, double R2, double n, double d){
    Eigen::Matrix2d A1;
    A1 << 1.0, (n-1.0)/R2, 0, 1.0;
    Eigen::Matrix2d A2;
    A2 << 1.0, 0, d/n, 1.0;
    Eigen::Matrix2d A3;
    A3 << 1.0, -(n-1.0)/R1, 0, 1.0;

    Eigen::Matrix2d A;
    A = A1*A2*A3;

    return A;
}

int main(int argc, char **argv) {
    const double R1 = std::stod(argv[1]);
    const double R2 = std::stod(argv[2]);
    const double d = std::stod(argv[3]);

    for (double n = 1; n <= 3; n+= 0.5){
    Eigen::Matrix2d A = operator_A(R1, R2, n, d);

    std::cout << "Matrix A with n " << n << ": \n" << A << std::endl;

    double det_A = A.determinant();
    double val_1_2 = -A(0,1);
    
    std::cout << "det: " << det_A << std::endl;
    std::cout << "1/f: " << val_1_2<< std::endl;
    std::cout << "\n" ;
    }
    return 0;
}