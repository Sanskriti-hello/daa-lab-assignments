
// // Problem Description:
// // Sort an array such that:
// // Elements with higher frequency appear first
// // If frequencies are equal, preserve their original relative order

// #include <iostream>
// using namespace std;
// #include <vector>
// #include <unordered_map>
// #include <algorithm>

// struct Item {
//     int value;
//     int frequency;
//     int index; 
// };

// bool compare(const Item &a, const Item &b){
//     if(a.frequency>b.frequency){
//         return true;
//     }
//     else if(a.frequency==b.frequency){
//         return a.index<b.index;
//     }
//     return false;
// };

// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     unordered_map<int, int> freqMap;
//     unordered_map<int, int> firstIndex;

//     for(int i=0;i<n;i++){
//         freqMap[arr[i]]++;
//         if(firstIndex.find(arr[i])==firstIndex.end()){
//             firstIndex[arr[i]]=i;
//         }
//     }

//     vector<Item> items;
//     for(int i=0;i<n;i++){
//         items.push_back({arr[i], freqMap[arr[i]], firstIndex[arr[i]]});
//     }
//     sort(items.begin(), items.end(), compare);
//     for(const Item &item : items){
//         cout<<item.value<<" ";
//     }
// }

// Problem Description:
// You are given a nearly sorted array in ascending order.
// Exactly one element is not in its correct position.

// Your task:
// Find the index of the misplaced element
// Move it to its correct position so the array becomes fully sorted
// You must use binary search to find the correct position.

#include <iostream>
using namespace std;
#include <vector>

int findInsertPosition(vector<int> &arr, int target, int left, int right) {
    while (left <= right) {
        int mid = right + (left - right) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int badIndex = -1;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            if (i > 0 && arr[i + 1] < arr[i - 1]) {
                badIndex = i + 1;
            } else {
                badIndex = i;
            }
            break;
        }
    }

    if (badIndex == -1) {
        for (int x : arr) {
            cout << x << " ";
        }
        return 0;
    }

    int badValue = arr[badIndex];
    arr.erase(arr.begin() + badIndex);

    int correctIndex = findInsertPosition(arr, badValue, 0, n - 2);
    arr.insert(arr.begin() + correctIndex, badValue);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}


// // Problem Description:
// // You are given a sorted array where:
// // Every element appears exactly k times
// // One element appears only once
// // k is an even number (e.g., 4, 6, …)

// // Find the single element using binary search in O(log n) time.

// #include <iostream>
// using namespace std;
// #include <vector>

// int binarySearch(vector<int> &arr, int left, int right, int k){
//     while(left<=right){
//         int mid = (left + right)/2;
//         int blockStart = mid - (mid % k);
//         if(blockStart + k - 1 > right){
//             right = blockStart - 1;
//             continue;
//         }

//         if(arr[blockStart]==arr[blockStart + k - 1]){
//             left = blockStart +k;
//         }
//         else{
//             right = blockStart;
//         }
//     }
//     return arr[left]; 
// };

// int main(){
//     int n, k;
//     cin>>n>>k;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int uniqueElement = binarySearch(arr, 0, n-1, k);
//     cout<<uniqueElement;
// }