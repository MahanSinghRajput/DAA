//quick select 
#include <iostream>
using namespace std;

int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r];
    int i = l;

    for(int j = l; j < r; j++) {
        if(arr[j] >= pivot) {   // >= for k-th largest
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int quickSelect(vector<int>& arr, int l, int r, int k) {
    if(l <= r) {
        int p = partition(arr, l, r);

        if(p == k - 1) return arr[p];
        if(p > k - 1) return quickSelect(arr, l, p - 1, k);
        return quickSelect(arr, p + 1, r, k);
    }
    return -1;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;   // 2nd largest

    cout << quickSelect(arr, 0, arr.size() - 1, k);
    return 0;
}

//using min heap
/*

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int x : nums) {
        pq.push(x);
        if(pq.size() > k)
            pq.pop();
    }

    return pq.top();
}

int main() {
    vector<int> v = {3,2,1,5,6,4};
    int k = 2;

    cout << findKthLargest(v, k);
}

*/