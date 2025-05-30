#include "matrix_utils.h"

int main(int argc, char **argv) {
    // read size of matrix
    if (argc != 3) {
        std::cerr << "Error. Usage:\n"
                  << argv[0] << " M N \n"
                  << "M : Rows\n"
                  << "N : Columns\n";
        return 1;
    }
    const int M = std::stoi(argv[1]);
    const int N = std::stoi(argv[2]);

    // create matrix A
    std::vector<double> A(M*N);

    // fill matrix randomly
    fill_matrix_random(A, M, N, 0); // 0 == seed

    // print matrix
    print_matrix(A, M, N);

    return 0;
}
