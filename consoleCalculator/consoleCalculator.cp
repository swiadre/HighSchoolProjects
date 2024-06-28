#include <iostream>
#include <string>

using namespace std;

int potega(int a, int b){
    int wynik = 1;
    if(b == 0)
        return 1;
    while(b != 0){
        wynik *= a;
        b--;
    }
    return wynik;
}

long long silnia(int a){
    long long wynik = 1;
    if(a == 0)
        return wynik;
    for(int i = 1; i<=a; i++){
        wynik = wynik * i;
    }
    return wynik;
}

int main() {
    int a, b;
    string opr;
    cout << "Oto kalkulator konsolowy!\n";
    do{
        cout << "Wprowadz pierwsza liczbe: ";
        cin >> a;
        cout << "Wprowadz druga liczbe: ";
        cin >> b;
        cout<< "Teraz podaj dzialanie jakie chcesz wykonac:\n "
            << "+ dla dodawania\n"
            << "- dla odejmowania\n"
            << "* dla mnozenia\n"
            << "/ dla dzielenia\n"
            << "^ dla potegi\n"
            << "! dla silni, zostanie wyswietlona silnia z pierwszej liczby\n"
            << "q dla wyjscia\n";
        cin >> opr;
        if(opr == "+"){
            cout << "Wynik dzialania to " << a+b << '\n';
        }
        else if(opr == "-"){
            cout << "Wynik dzialania to " << a-b << '\n';
        }
        else if(opr == "*"){
            cout << "Wynik dzialania to " << a*b << '\n';
        }
        else if(opr == "/"){
            if(b != 0)
                cout << "Wynik dzialania to " << a/b << '\n';
            else
                cout << "Nie wolno dzielic przez 0!!!\n";
        }
        else if(opr == "^"){
            cout << "Wynik dzialania to " << potega(a, b) << '\n';
        }
        else if(opr == "!"){
            cout << "Wynik dzialania to " << silnia(a) << '\n';
        }
        else if(opr == "q"){
            cout << "Zamykam program...";
            return 0;
        }
        else{
            cout << "Podano zly operator!!!\n";
        }
    }while(opr != "q");

    return 0;
}