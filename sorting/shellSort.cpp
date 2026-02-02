#include<iostream>
using namespace std;
void shellSort(int* arr, int n){
    for(int gap = n/2; gap >= 1; gap /= 2){
        for(int j = gap; j < n; j++){
            for(int i = j-gap; i >= 0; i -= gap){
                if(arr[i + gap] > arr[i]) break;
                else swap(arr[i+gap],arr[i]);
            }
        }
    }
}

//optimised Shell Sort
void optimisedShellSort(int* arr, int n){
    int gap = 1;
    while(gap < n/3)
        gap = gap * 3 + 1;   // Knuth sequence
    while(gap >= 1){
        for(int j = gap; j < n; j++){
            for(int i = j - gap; i >= 0 && arr[i] > arr[i + gap]; i -= gap){
                swap(arr[i], arr[i + gap]);
            }
        }
        gap /= 3;
    }
}

//Shell Sort with Ciura gaps - best and used in real systems
void bestShellSort(int* arr, int n) {

    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};

    for(int g = 0; g < 8; g++){
        int gap = gaps[g];

        if(gap > n) continue;   // skip big gaps

        for(int j = gap; j < n; j++){
            for(int i = j - gap; i >= 0 && arr[i] > arr[i + gap]; i -= gap){
                swap(arr[i], arr[i + gap]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << "before sorting : ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
    shellSort(arr,n);
    cout << "after sorting : ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}