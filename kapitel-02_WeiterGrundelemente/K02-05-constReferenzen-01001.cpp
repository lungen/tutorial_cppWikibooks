#include <iostream>


void ausgabe1(int wert) {

    std::cout << "wert: " << wert << "\n";

}


void ausgabe2(int const &wert) {

    std::cout << "wert: " << wert << "\n";

}


int main() {

    ausgabe1(5);

    ausgabe2(7);

    return (0);

}

