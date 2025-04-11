/*
Juego de adivinar un numero

Tener un numero
Preguntar al usuario el numero
Informar si lo adivino o no

*/

#include <iostream>
#include <random>

//declaracion
void juego(int min_val, int max_val);


int main(void) {
    juego(1, 100);
    juego(5, 75);

    return 0;
}

//Implementacion
void juego(int min_val, int max_val)
{
    //colocar el numero aleatorio
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int>distro(min_val, max_val);

    const int NUM = distro(gen);
    int guessed_number = NUM/2;

    const int MIN = min_val;
    const int MAX = max_val;

    std::cout <<"\nINICIA EL JUEGO\n";

    while(guessed_number != NUM){
        std::cout <<"Adivina un numero entre " << MIN << " y " << MAX << ":\n";
        std::cin >> guessed_number;
        //std::cout <<"Escribiste: " << guessed_number << "\n";

        // validacion del rango 
        if (guessed_number < MIN or guessed_number>MAX){
            std::cout << "Estas fuera del rango. Vuele a intentarlo.\n";
            continue;
        }

        if (guessed_number == NUM){
            std::cout <<"GANASTE!!!\n";
        } else if (guessed_number > NUM){
            std::cout <<"Te pasaste\n";
        } else { // es menor
            std::cout <<"Te falta\n";
    }
    }
}