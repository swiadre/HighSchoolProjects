// Przed uruchumieniem programu prosze sie upewnic czy plik "jawny.txt" istnieje
// przepraszam tez za spoznienie ale mialem problem ze zrobieniem tego zadania
// lecz mam nadzieje ze efekt koncowy jest dobry

#include <bits/stdc++.h>

using namespace std;

long long potModularne(long long podstawa, long long wykladnik, long long modulus){
    long long wynik = 1;
    podstawa = podstawa % modulus;

    while (wykladnik > 0){
        if (wykladnik % 2 == 1)
            wynik = (wynik * podstawa) % modulus;

        podstawa = (podstawa * podstawa) % modulus;
        wykladnik /= 2;
    }

    return wynik;
}

long long rae(long long a, long long b, long long& x, long long& y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }

    long long x1, y1;
    long long nwd = rae(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return nwd;
}

void szyfruj(const string& plikJawny, const string& plikSzyfrogram, long long kluczPubliczny, long long modulus){
    ifstream plikWejsciowy(plikJawny);
    ofstream plikWyjsciowy(plikSzyfrogram);

    if (!plikWejsciowy){
        return;
    }

    if (!plikWyjsciowy){
        return;
    }

    char znak;
    vector<long long> zaszyfrowaneBloki;

    while (plikWejsciowy.get(znak)){
        auto wartoscZnaku = static_cast<long long>(znak);
        long long zaszyfrowanaWartosc = potModularne(wartoscZnaku, kluczPubliczny, modulus);

        zaszyfrowaneBloki.push_back(zaszyfrowanaWartosc);
    }

    for (const long long& blok : zaszyfrowaneBloki)
        plikWyjsciowy << blok << " ";

    plikWejsciowy.close();
    plikWyjsciowy.close();
}

void deszyfruj(const string& plikSzyfrogram, const string& plikOdszyfrowany, long long kluczPrywatny, long long modulus){
    ifstream plikWejsciowy(plikSzyfrogram);
    ofstream plikWyjsciowy(plikOdszyfrowany);

    if (!plikWejsciowy){
        return;
    }

    if (!plikWyjsciowy){
        return;
    }

    long long blok;

    while (plikWejsciowy >> blok){
        long long odszyfrowanaWartosc = potModularne(blok, kluczPrywatny, modulus);
        char znak = static_cast<char>(odszyfrowanaWartosc);
        plikWyjsciowy << znak;
    }

    plikWejsciowy.close();
    plikWyjsciowy.close();
}

int main(){
    // q = 11
    // p = 13
    // f eulera = 120
    // modul n = 143
    // e = 7
    // d = 103
    // klucz publiczny = (7, 143)
    // klucz prywatny = (103, 143)

    long long kluczPubliczny = 7;
    long long kluczPrywatny = 103;
    long long modulus = 143;

    szyfruj("jawny.txt", "szyfrogram.txt", kluczPubliczny, modulus);
    deszyfruj("szyfrogram.txt", "odszyfrowany.txt", kluczPrywatny, modulus);

    return 0;
}