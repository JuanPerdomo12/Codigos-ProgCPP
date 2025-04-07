#include <iostream>
#include <string> //es importante para getline

int main(void) {
    std::string nombre; //aqui declaro una variable

    std::cout << "Ingresar nombre: ";
    std::getline(std::cin, nombre);

    std::cout <<"Hola, " <<nombre<< "!\n";
    return 0;
}