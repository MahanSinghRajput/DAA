#include<iostream>
using namespace std;
void bubbleSort(int* arr, int n){
    for(int i=n-1;i>=1;i--){
        int didSwap = 0;
        for(int j=0;j<=i-1;j++){
            if(arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0) return;
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
    bubbleSort(arr,n);
    cout << "after sorting : ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}