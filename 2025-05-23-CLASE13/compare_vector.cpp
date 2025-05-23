#include <vector>
#include <iostream>
#include <string>

int main(void)
{
    // declare the vector
    std::vector<double> data = {2, 3, 4, 5, 6}; 

    std::cout << &data[0] << "\n";

    // resize the vector
    data.push_back (10);

    std::cout << &data[0] << "\n";

    return 0;
}