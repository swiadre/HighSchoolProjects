#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int binarySearch(int l, int r, int target, int arr[]){
    if(r >= l){
        int mid;
        mid = (r + l) / 2;

        if(arr[mid] == target){
            return mid;
        }

        if(target > arr[mid]){
            return binarySearch(mid + 1, r, target, arr);
        }
        else{
            return binarySearch(l, mid-1, target, arr);
        }
    }
    else{
        return -1;
    }
}

int binarySearch2(int l, int r, int target, int arr[]){
    int mid;
    while(r >= l){
        mid = (r + l) / 2;
        if(arr[mid] == target) return mid;
        if(target > arr[mid]){
            l = mid+1;
            continue;
        }
        if(target < arr[mid]){
            r = mid-1;
            continue;
        }
    }
}

int main(){
    int n = 10;
    int tab[n];
    for(int i = 0; i < 10; i++){
        tab[i] = rand()%n + 1;
    }
    sort(tab, tab+n);
    for(int i = 0; i < 10; i++){
        cout << "index: " << i << " value: " << tab[i] << '\n';
    }
    cout << "result: "<< binarySearch(0, n, 5, tab) << '\n';
    cout << "result2: " << binarySearch2(0, n, 8, tab);
}
