#include<iostream>
using namespace std;
void bucketSort(float* arr, int n){
    // Create n buckets
    vector<vector<float>> buckets(n);

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i]; 
        buckets[index].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (float x : buckets[i]) {
            arr[k++] = x;
        }
    }
}
int main(){
    int n;
    cin >> n;
    float arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << "before sorting : ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
    bucketSort(arr,n);
    cout << "after sorting : ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}