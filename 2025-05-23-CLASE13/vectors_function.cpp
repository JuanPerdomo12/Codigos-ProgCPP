#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

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
    auto print = [](double x){std::cout << x << "\n";};

    // fill
    int ii = 0;
    auto fill = [&ii](double & x){x = ii; ii++;};
    std::for_each(data.begin(), data.end(), fill);

    std::for_each(data.begin(), data.end(), print);

    // compute the average
    std::cout << std::accumulate(data.begin(), data.end(), 0.0)/data.size() << "\n";

    return 0;
}
