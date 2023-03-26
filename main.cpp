#include "dll.h"


int main() {
    auto startTime = std::chrono::high_resolution_clock::now();

    string vardas;
    string dienos[2];
    string laikas[2];
    cout << "Koks vartotojo vardas?" << endl;
    cin >> vardas;
    cout << "Nuo kurios dienos gali buti prie kompiuterio?" << endl;
    cin >> dienos[0];
    cout << "Iki kurios dienos gali buti prie kompiuterio?" << endl;
    cin >> dienos[1];
    cout << "kuriuo laiku gali pradeti naudoti kompiuteri?" << endl;
    cin >> laikas[0];
    cout << "kuriuo laiku turi baigti naudoti kompiuteri?" << endl;
    cin >> laikas[1];
    //system(ribojimas(vardas, dienos, laikas).c_str());
    
    int studid = 2110260;
    char answer;
    double F = 1;
    double x0 = studid%19; //6
    double xn = studid%25; //10
    //cout << x0 << " " << xn << endl;
    //double dx = studid*1.0/1000000000000; - OG
    double dx = studid * 1.0 / 1000000000;
    //double dx = 0.5;
    //calculateTschirnhausen(F, x0, xn, dx);
    do
    {
        
        cout << "ar norite vykdyti Tschirnhausen algoritma ? (Y/N)" << endl;
        cin >> answer;
        if (answer != 'Y') break;
        cout << "Iveskite F reiksme" << endl;
        cin >> F;
        nested_folders();
        calculateTschirnhausen(F, x0, xn, dx);
        merge(F);
        delete_root();
        
    } while(true);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
    cout << "Programa uztruko: " << duration.count() << " sekundziu" << endl;

    return 0;
}
