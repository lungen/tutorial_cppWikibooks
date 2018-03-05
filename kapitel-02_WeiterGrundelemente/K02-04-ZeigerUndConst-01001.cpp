#include <iostream>

using namespace std;

int main()
{
    int wert1 = 1;
    int wert2 = 22;

    int *pWert1 = &wert1;
    int *pWert2;
    pWert2 = &wert2;

    // (1) const Variable ->  der Wert der Variable wert1 kann nicht ueber den Zeiger veraendert werden.
    int const *pConstWert1 = &wert1;
    // *pConstWert1 = 3; => FAIL

    // (2) const Zeiger -> der Zeiger kann nicht auf eine andere Variable (Adresse) umgebogen werden.
    int *const pConstWert2 = &wert2;
    // z.B: pConstWert2 = &wert2; => FAIL

    // (3) const Zeiger const Variable -> werder der Wert des Zeigers noch der Variable duerfen
    // veraendert werden.
    int wert3 = 33;
    int const * const pConstWert3 = &wert3;
    // pConstWert3 = &wert1; => FAIL
    // *pConstWert3 = 44; => FAIL => FAIL => FAIL


    cout << "*pWert1: " << pWert1 << " -> " << *pWert1 << endl;
    cout << "*pWert2: " << pWert2 << " -> " << *pWert2 << endl;
    cout << "*pConstWert1: " << pConstWert1 << " -> " << *pConstWert1 << endl;

    cout << "*pConstWert2: " << pConstWert2 << " -> " << *pConstWert2 << endl;
    *pConstWert2 = 3;
    cout << "*pConstWert2: " << pConstWert2 << " -> " << *pConstWert2 << endl;
    cout << "*pConstWert3: " << pConstWert3 << " -> " << *pConstWert3 << endl;
    cout << "*pConstWert3: " << pConstWert3 << " -> " << *pConstWert3 << endl;

    return 0;
}

