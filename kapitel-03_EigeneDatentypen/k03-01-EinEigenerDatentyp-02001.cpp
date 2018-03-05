#include <iostream>
#include <typeinfo>

using namespace std;


class Auto{
    public:
        /// Konstruktor und Initialisierung
        // Initialisierungs-Liste
        Auto(int tankGroesse, float tankInhalt = 40.0, float verbrauch = 5.0):
            tankGroesse_(tankGroesse),
            tankInhalt_(tankInhalt),
            verbrauch_(verbrauch)
            {}

        void info()const;
        void fahren(int km);
        void tanken(float liter);

    private:
        int tankGroesse_;
        float tankInhalt_;
        float verbrauch_;

};

void Auto::info()const{
    cout << "Tankgroesse:   " << tankGroesse_ << " Liter.\n";
    cout << "Tankinhalt:    " << tankInhalt_ << " Liter.\n";
    cout << "Verbrauch:     " << verbrauch_ << " Liter pro 100 km.\n";
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
    Auto skoda(80, 60, 5);
    cout << "skoda: \n";
    skoda.info();

    Auto fiat(60);
    cout << "fiat: \n";
    fiat.info();

    Auto ford(75, 66, 10);
    cout << "ford: \n";
    ford.info();

    return 0;
}
