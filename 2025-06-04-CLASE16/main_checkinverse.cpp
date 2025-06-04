#include "matrix_utils.h"

int main(int argc, char **argv) {
    // read size of matrix
    if (argc != 5) {
        std::cerr << "Error. Usage:\n"
                  << argv[0] << " M N \n"
                  << "M : Rows\n"
                  << "N : Columns\n";
        return 1;
    }
    const int M1rows = std::stoi(argv[1]);
    const int M1cols = std::stoi(argv[2]);
    const int M2rows = std::stoi(argv[3]);
    const int M2cols = std::stoi(argv[4]);

    // create matrix 
    std::vector<double> A(M1rows*M1cols);

    std::vector<double> B(M2rows*M2cols);

    std::vector<double> I(M1rows*M1cols);

    // fill matrix
    fill_matrix(A, M1rows, M1cols);

    fill_matrix(B, M2rows, M2cols);

    // matrix multi
    std::vector<double> C(M1cols*M2rows);
    matrix_matrix_multi(A, B, C, M1rows, M1cols, M2rows, M2cols);

    // identity
    identity_matrix(I, M1rows);

    // print matrix
    print_matrix(A, M1rows, M1cols);

    print_matrix(B, M2rows, M2cols);

    print_matrix(C, M1rows, M2cols);

    print_matrix(I, M1rows, M1cols);

    // check inverse
    check_inverse(A, B, I, 0.01, 4);

    return 0;
}