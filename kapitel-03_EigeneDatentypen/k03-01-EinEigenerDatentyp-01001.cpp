#include <iostream>

using namespace std;

class Auto{

    public:
        Auto(int tankInhalt, float tankfuellung, float verbrauch);

        void info()const;
        void fahren(int km);
        void tanken(float liter);

    private:
        int tankInhalt_;
        float tankfuellung_;
        float verbrauch_;
};

Auto::Auto(int tankInhalt, float tankfuellung, float verbrauch):
    // Initialisierungs-Liste
    tankInhalt_(tankInhalt),
    tankfuellung_(tankfuellung),
    verbrauch_(verbrauch)
    {}

void Auto::info()const{
    cout << "In den Tank passen: " << tankInhalt_ << " Liter!\n";
    cout << "Tang ist " << tankfuellung_ << " voll\n";
    cout << "Der Wagen verbraucht " << verbrauch_ << " Liter pro 100 km/h\n";
    cout << endl;
}

void Auto::fahren(int km){
    cout << "fahre " << km << " km\n";

    tankfuellung_ -= verbrauch_ * km/100;

    if (tankfuellung_ <= 0.0){
        cout << "Der Wagen ist Unterwegs stehen geblieben. Zeit zum tanken\n";
    }
    cout << endl;
}

void Auto::tanken(float liter){
    cout << "Tanke " << liter << " Liter.\n";
    tankfuellung_ += liter;

    if (tankfuellung_ >= tankInhalt_){
        cout << "Tank ist voll -> Benzin ist uebergegangen!\n";
    }
    cout << endl;

}


int main()
{
    Auto skoda(80, 60, 5);
    skoda.info();
    skoda.fahren(200);
    skoda.info();
    skoda.fahren(2000);
    skoda.info();
    skoda.tanken(100);
    skoda.info();

    return 0;
}

