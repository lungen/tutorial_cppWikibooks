/* INIT()
 * Wenn mehrere Konstruktoren das gleiche tun, ist es oft sinnvoll, diese gleichen
 * Teile in eine eigene Methode (üblicherweise mit dem Namen init()) zu schreiben.
 * Das ist kürzer, übersichtlicher, meist schneller und hilft auch noch bei der
 * Vermeidung von Fehlern. Denn wenn Sie den Code nachträglich ändern, dann müssten
 * Sie diese Änderungen für jeden Konstruktor vornehmen. Nutzen Sie eine init()-Methode,
 * müssen Sie den Code nur in dieser ändern.
 */


#include <iostream>

using namespace std;


class Auto{
    public:
        /// Konstruktoren Deklarationen
        Auto(int tankGroesse, float tankInhalt, float verbrauch);
        Auto(int tankGroesse);

        void info()const;
        void fahren(int km);
        void tanken(float liter);

    private:
        void init();
        int tankGroesse_;
        float tankInhalt_;
        float verbrauch_;
        int maxSpeed_;

};

/// Konstruktoren Definitionen
// Initialisierungs-Liste
Auto::Auto(int tankGroesse, float tankInhalt, float verbrauch):
    tankGroesse_(tankGroesse),
    tankInhalt_(tankInhalt),
    verbrauch_(verbrauch)
    {
    init();
    }

// Initialisierungs-Liste
Auto::Auto(int tankGroesse):
    tankGroesse_(tankGroesse),
    tankInhalt_(30.0),
    verbrauch_(7.0)
    {
    init();
    }

void Auto::init(){
    maxSpeed_ = 180;
    tankGroesse_ = 100;

}

void Auto::info()const{
    cout << "Tankgroesse:   " << tankGroesse_ << " Liter.\n";
    cout << "Tankinhalt:    " << tankInhalt_ << " Liter.\n";
    cout << "Verbrauch:     " << verbrauch_ << " Liter pro 100 km.\n";
    cout << "maximale Geschwindigkeit: " << maxSpeed_ << " km/h.\n";
    cout << endl;
}

void Auto::fahren(int km){
    cout << "Auto ist " << km << " km gefahren!" << endl;

    tankInhalt_ -= verbrauch_ * km/100;
    if (tankInhalt_ <= 0.0){
        cout << "Benzin ist aus. Bitte tanken!\n";
    }

    cout << endl;
}

void Auto::tanken(float liter){
    cout << "Es wurde " << liter << " getankt.\n";
    tankInhalt_ += liter;

    if (tankInhalt_ > tankGroesse_){
        cout << "Zu viel getankt: " << tankInhalt_ << " Liter.\n";
        tankInhalt_ = tankGroesse_;
    }

    cout << endl;
}


int main()
{
    Auto skoda(80, 60, 5.0);
    cout << "skoda: \n";
    skoda.info();

    Auto fiat(60);
    cout << "fiat: \n";
    fiat.info();

    Auto ford(75, 66, 10.0);
    cout << "ford: \n";
    ford.info();

    return 0;
}
