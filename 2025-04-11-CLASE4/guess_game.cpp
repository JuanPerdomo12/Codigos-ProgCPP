/*
Juego de adivinar un numero

Tener un numero
Preguntar al usuario el numero
Informar si lo adivino o no

*/

#include <iostream>

int main(void) {
    const int NUM = 10;
    int guessed_number = NUM/2;

    while(guessed_number != NUM){
        std::cout <<"Adivina un numero entre 1 y 100:\n";
        std::cin >> guessed_number;
        //std::cout <<"Escribiste: " << guessed_number << "\n";

        // validacion del rango 
        if (guessed_number < 1 or guessed_number>100){
            std::cout << "Estas fuera del rango. ¡Se termina el juego!\n";
            break;
        }
        
        if (guessed_number == NUM){
            std::cout <<"GANASTE!!!\n";
        } else if (guessed_number > NUM){
            std::cout <<"Te pasaste\n";
        } else { // es menor
            std::cout <<"Te falta\n";
    }
    }

    return 0;
}