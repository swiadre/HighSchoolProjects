#include <iostream>
#include <fstream>
#include <string>


using namespace std;


ifstream in;
ofstream out;


void szyfruj();
void odszyfruj();


int main() {
    char option;

    string tekst = "";                  // tekst do pliku na ktorym bedziemy operowac

    cout << "Wpisz tekst do pliku tekst.txt: ";

    out.open("tekst.txt");

    if(out.good()){
        getline(cin, tekst);
        out << tekst;
        out.close();
    }

    else
        cout << "Blad utworzenia pliku" << '\n';


    cout << "Wybierz opcje: " << '\n'
         << "1. Zaszyfruj tekst podany przed chwila" << '\n'
         << "2. Odszyfruj tekst z poprzedniego uruchomienia programu" << '\n'
         << "3. Kliknij " << 'q' << " aby zakonczyc dzialanie programu" << '\n';

    cin >> option;

    switch (option) {                   // opcje podane w tresci zadania
        case '1':
            szyfruj();
            break;
        case '2':
            odszyfruj();
            break;
        case 'q':
            break;
        default:
            cout << "ZOSTALA WYBRANA NIEPOPRAWNA OPCJA!!!" << '\n';
    }


    cout << "Dziekuje za wspolprace!";
    return 0;
}


void szyfruj(){
    cout << "Podaj klucz w zakresie [0:1000]: ";
    int k;                              // przesuniecia
    cin >> k;
    cout << '\n';

    string tekst="";
    in.open("tekst.txt");            // tekst do zaszyfrowania

    if(in.good()){
        getline(in, tekst);
    }

    else
        cout << "Blad otwarcia pliku" << '\n';


    if(k>26)                           // szyfrowanie tekstu
        k = k % 26;

    for(int i = 0; i < tekst.length(); i++){
        if(tekst[i] == ' ')
            continue;
        tekst[i] += k;

        if(tekst[i] > 'Z')
            tekst[i] -= 26;
    }

    out.open("szyfrogram.txt");    // wypis do pliku

    if(out.good()){
        out << tekst;
        out.close();
    }

    else
        cout << "Blad utworzenia pliku" << '\n';

    cout << "Zaszyfrowany tekst znajduje sie w pliku szyfrogram.txt" << '\n';
}


void odszyfruj(){
    cout << "Podaj klucz w zakresie [0:1000]: ";
    int k;                              // przesuniecia
    cin >> k;
    cout << '\n';

    string tekst="";
    in.open("szyfrogram.txt");              // tekst do odszyfrowania

    if(in.good()){
        getline(in, tekst);
    }

    else
        cout << "Blad otwarcia pliku" << '\n';


    if(k>26)                                   // odszyfrowanie tekstu
        k = k % 26;

    for(int i = 0; i < tekst.length(); i++){
        if(tekst[i] == ' ')
            continue;
        tekst[i] -= k;

        if(tekst[i] < 'A')
            tekst[i] += 26;
    }

    out.open("odszyfrowany.txt");           // wypis do pliku

    if(out.good()){
        out << tekst;
        out.close();
    }

    else
        cout << "Blad utworzenia pliku" << '\n';
    cout << "Odszyfrowany tekst znajduje sie w pliku odszyfrowany.txt" << '\n';
}