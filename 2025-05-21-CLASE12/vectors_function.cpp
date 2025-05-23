#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

double average_vector(const std::vector<double> & x);
void fill (std::vector<double> & x);

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

    // print
    auto print = [](double x){std::cout << x << "\n"};

    // fill
    int ii = 0;
    auto fill = [&ii](double & x){x = ii; ii++};
    std::for_each(data.begin(), data.end(), fill);

    std::for_each(data.begin(), data.end(), print);


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

/*void fill(std::vector<double> & x){
    // initialize the data
    for(int ii = 0; ii < x.size(); ii++) {
        x[ii] = ii;
    }
}*/
