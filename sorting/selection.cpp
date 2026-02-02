#include<iostream>
using namespace std;
void selectionSort(int* arr, int n){
    for(int i=0;i<n-1;i++){
        int mini = i;
        for(int j=i;j<n;j++){
            if(arr[j] < arr[mini]) mini = j;
        }
        swap(arr[mini],arr[i]);
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
    selectionSort(arr,n);
    cout << "after sorting : ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}