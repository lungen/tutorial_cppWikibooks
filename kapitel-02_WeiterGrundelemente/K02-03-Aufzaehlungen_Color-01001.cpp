#include <iostream>

using namespace std;

enum color{
    red,
    green,
    blue
};

int main()
{
    color actualColor = red;
    int input;

    // Eingabe bis input einen Wert hat, der einem Indizes entspricht
    do{
        cout << "Input: ";
        cin >> input;
    }while(input < red || input > blue);

    actualColor = color(input); // explizite Umwandlung nach color

    switch(actualColor){
        case red: cout << "red -> " << input << endl; break;
        case green: cout << "green -> " << input << endl; break;
        case blue: cout << "blue -> " << input << endl; break;
    }

    return 0;
}

