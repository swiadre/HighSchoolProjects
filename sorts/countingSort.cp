#include <iostream>
#include <cstdlib>

using namespace std;

void countingSort(int tab[], int n){
    int max = tab[0];
    int min = tab[0];

    for (int i = 1; i < n; i++) {
        if (tab[i] > max)
            max = tab[i];
    }

    for (int i = 1; i < n; i++) {
        if (tab[i] < min)
            min = tab[i];
    }

    int counters = max - min + 1;
    int count[counters];

    for(int i = 0; i < counters; i++){
        count[i] = 0;
    }

    for(int i = 0; i < n; i++){
        count[tab[i]-min]++;
    }

    for(int i = 0; i < counters; i++){
        while(count[i] > 0){
            cout << min + i << ' ';
            count[i] --;
        }
    }
}

// zlozonosc o(n + max-min)

int main(){
    int n;
    cin >> n;
    int tab[n];

    for(int i = 0; i < n; i++){
        tab[i] = rand() % n + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << tab[i] << ' ';
    }

    cout << "\n\n";

    countingSort(tab, n);
}
