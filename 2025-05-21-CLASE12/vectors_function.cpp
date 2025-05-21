#include <vector>
#include <iostream>
#include <string>

double average_vector(const std::vector<double> & x);

int main(int argc , char **argv)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    // declare the vector
    std::vector<double> data; 

    // read the size from the command line
    const int N = std::stoi(argv[1]); 

    // resize the vector
    data.resize(N, 0);

    // initialize the data
    for(int ii = 0; ii < N; ii++) {
        data[ii] = ii;
    }

    // compute the average
    double avg = average_vector(data);

    std::cout << avg << "\n";

    return 0;
}

double average_vector(const std::vector<double> & x){
    double suma = 0.0;
    for (int ii= 0; ii < x.size(); ii++) {
        suma = suma + x[ii];
    }
    return suma/x.size();
}
