#include "matrix_utils.h"
void print_matrix(const std::vector<double> & M, int nrows, int ncols){
    std::cout.setf(std::ios::scientific);
    std::cout.precision(15);

    for (int ii = 0; ii < nrows; ++ii) {
        for (int jj = 0; jj < ncols; ++jj) {
            std::cout << M[ii*ncols + jj] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed){
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dis(-1, 1);
    for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols; jj++){
            M[ii*ncols + jj] = dis(gen);
        }
    }

}

double trace_matrix(const std::vector<double> & M, int nrows, int ncols){
    std::cout.setf(std::ios::scientific);
    std::cout.precision(15);

    double sum = 0.0;

    for (int ii = 0; ii < nrows; ++ii) {
        for (int jj = 0; jj < ncols; ++jj) {
            if (ii == jj){
                sum += M[ii*ncols + jj];
            }
        }
    }
    std::cout << "Trace = " << sum << "\n";
    return sum;
}

void fill_matrix(std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      data[ii*n + jj] = ii*n+jj; // A_(i, j) = i*n + j = id
    }
  }
}

void matrix_matrix_multi(const std::vector<double> & M1, const std::vector<double> & M2, 
            std::vector<double> & MM, int M1rows, int M1cols, int M2rows, int M2cols){
                if (M1cols != M2rows){
                    std::cerr << "Matrix 1 must have the same columns as rows of Matrix 2\n";
                    return ;
                }

                MM.assign(M1rows*M2cols, 0.0);

                for (int i = 0; i < M1rows; i++){
                    for (int j = 0; j < M2cols; j++){
                        for (int k = 0; k < M1cols; k++){
                            MM[i*M2cols + j] += M1[i*M1cols + k] * M2[k*M2cols + j];
                        }
                    }
                }
            }

void identity_matrix(std::vector<double> & I, int nrows){
    std::cout.setf(std::ios::scientific);
    std::cout.precision(15);

    I.resize(nrows*nrows, 0.0);

    for (int ii = 0; ii < nrows; ++ii) {
        for (int jj = 0; jj < nrows; ++jj) {
            if (ii == jj){
                I[ii*nrows+jj]=1.0;
            }
        }
    }
}

bool check_inverse(const std::vector<double> & A, const std::vector<double> & B, const std::vector<double> & I_n, double epsilon, int n){
    std::vector<double> C;
    std::vector<double> D;
    matrix_matrix_multi(A,B,C,n,n,n,n);
    for(int ii = 0; ii < n; ii++){
        for(int jj = 0; jj < n; jj++){
            D[ii*n+jj] = C[ii*n+jj] - I_n[ii*n+jj];         
        }
    }
    for(int ii = 0; ii < n; ii++){
        for(int jj = 0; jj < n; jj++){
            if (D[ii*n+jj] > epsilon or D[ii*n+jj] < -epsilon){
            return false;
        }
    }
    }
    return true;
}