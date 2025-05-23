#include <iostream>

int main(void){
int * dynamic_array = new int[5];
dynamic_array[0] = 2;
dynamic_array[1] = 3;
dynamic_array[2] = 4;
dynamic_array[3] = 5;
dynamic_array[4] = 6;

std::cout << &dynamic_array[0] << "\n";

delete[] dynamic_array;

int * new_dynamic_array = new int[6];
new_dynamic_array[0] = 2;
new_dynamic_array[1] = 3;
new_dynamic_array[2] = 4;
new_dynamic_array[3] = 5;
new_dynamic_array[4] = 6;
new_dynamic_array[5] = 10;
std::cout << &new_dynamic_array[0] << "\n";

delete[] new_dynamic_array;
return 0;
}
