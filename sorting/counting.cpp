#include<iostream>
using namespace std;
void countingSort(int* arr, int n){
    int maxval = 0;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, arr[i]);

    // create and initialize cntArr array
    vector<int> cntArr(maxval + 1, 0);

    // count frequency of each element
    for (int i = 0; i < n; i++)
        cntArr[arr[i]]++;

    // compute prefix sum
    for (int i = 1; i <= maxval; i++)
        cntArr[i] += cntArr[i - 1];

    // build output array
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[cntArr[arr[i]] - 1] = arr[i];
        cntArr[arr[i]]--;
    }
    for(int i=0;i<n;i++) arr[i] = ans[i];
}

//for negatives
void countingSortNegatives(int* arr, int n) {
    int minVal = arr[0], maxVal = arr[0];

    // find min and max
    for (int i = 1; i < n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    int range = maxVal - minVal + 1;

    // count array
    vector<int> cntArr(range, 0);

    // frequency count
    for (int i = 0; i < n; i++)
        cntArr[arr[i] - minVal]++;

    // prefix sum
    for (int i = 1; i < range; i++)
        cntArr[i] += cntArr[i - 1];

    // output array (stable)
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int idx = arr[i] - minVal;
        ans[cntArr[idx] - 1] = arr[i];
        cntArr[idx]--;
    }

    // copy back
    for (int i = 0; i < n; i++)
        arr[i] = ans[i];
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << "before sorting : ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
    countingSort(arr,n);
    cout << "after sorting : ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}