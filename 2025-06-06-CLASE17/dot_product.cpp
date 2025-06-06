#include <iostream> 
#include <valarray>
#include <cmath>

int main(void){
    std::valarray<int> v1 = {1,2,3,4,5};
    std::valarray<int> v2 = {1,2,3,4,5};

    std::cout << (v1*v2).sum() << std::endl;

    return 0;
}