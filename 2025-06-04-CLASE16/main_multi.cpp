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

    // create matrix M
    std::vector<double> M1(M1rows*M1cols);

    std::vector<double> M2(M2rows*M2cols);

    // fill matrix
    fill_matrix(M1, M1rows, M1cols);

    fill_matrix(M2, M2rows, M2cols);

    // print matrix
    print_matrix(M1, M1rows, M1cols);

    print_matrix(M2, M2rows, M2cols);

    // matrix multi
    std::vector<double> MM(M1cols*M2rows);
    matrix_matrix_multi(M1, M2, MM, M1rows, M1cols, M2rows, M2cols);

    print_matrix(MM, M1rows, M2cols);

    return 0;
}