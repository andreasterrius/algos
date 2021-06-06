#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
                for(int _j = 0; _j < y; ++_j) \
                    cout << arr[_i][_j] << " "; \
                cout << "\n"; }
#define MODL 1000000007

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 1*(2+3)

void merge(vector<int>& arr, int left, int mid, int right) {

    vector<int> temp;

    // 4 5 7
    int first = left;
    
    // 1 9 23
    int second = mid+1;
    
    // 1
    while (first <= mid && second <= right) {
        if (arr[first] > arr[second]) {
            temp.push_back(arr[first]);
            first++;
        }
        else {
            temp.push_back(arr[second]);
            second++;
        }
    }

    for (int i = first; i <= mid; ++i) temp.push_back(arr[i]);
    for (int i = second; i <= right; ++i) temp.push_back(arr[i]);

    int ctr = 0;
    for (int i = left; i <= mid; ++i) {
        arr[i] = temp[ctr];
        ctr++;
    }

    for (int i = mid + 1; i <= right; ++i) {
        arr[i] = temp[ctr];
        ctr++;
    }
}

void mergeSortInternal(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSortInternal(arr, left, mid);
    mergeSortInternal(arr, mid+1, right);
    merge(arr, left, mid, right);
}

void mergeSort(vector<int> &arr) {
    // Split into 2
    mergeSortInternal(arr, 0, arr.size() - 1);
}


/*
*/

int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}

    //cout << parse("2*(10-2)");
    vector<int> d{ 3, 2, 1};
    mergeSort(d);

    debuglist(d);

    return 0;
}
