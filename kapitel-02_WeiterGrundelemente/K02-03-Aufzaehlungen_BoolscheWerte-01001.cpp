#include <iostream>

using namespace std;

enum font{
    italic = 0x01,
    bold = 0x02,
    underline = 0x04
};

int main()
{
    font flags = font(0); // kein flag gesetzt
    char input;

    cout << "flags: " << flags << endl;

    cout << "Kursivdruck? ";
    cin >> input;
    // Binaeres Oder zum Setzen eines Flags (flags | italic => int)
    if(input == 'j') flags = font(flags | italic);
    cout << "flags: " << flags << endl;

    cout << "Fettdruck? ";
    cin >> input;
    // Binaeres Oder zum Setzen eines Flags (flags | italic => int)
    if(input == 'j') flags = font(flags | bold);
    cout << "flags: " << flags << endl;


    cout << "Unterstricken? ";
    cin >> input;
    // Binaeres Oder zum Setzen eines Flags (flags | italic => int)
    if(input == 'j') flags = font(flags | underline);
    cout << "flags: " << flags << endl;

    // Binaeres Und zum Abfragen des Flags
    if(flags & italic) cout << "Der Text ist kursiv: " << flags << endl;
    if(flags & bold) cout << "Der Text ist fett: " << flags << endl;
    if(flags & underline) cout << "Der Text ist unterstrichen: " << flags << endl;
    if(flags == 0) cout << "Der Text wird normal ausgegeben: " << flags << endl;

    return 0;
}

