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

typedef long long ll;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
        for(int _j = 0; _j < y; ++_j) \
            cout << arr[_i][_j] << " "; \
        cout << "\n"; }
#define MODL 1000000007

/*
* Binary search - Next Integer Permutation
* Accepted
algorithm:
Find whether 
the number is already sorted yet or not;
if it isn't find the first index where the ascending
order is violated
ex:
5142
then (14) violates the order here since 1 < 4
we then the lowest viable replacment for 1 (which is 2)
but it cannot be lower than 1 (since it will not be the next bigger permut)

we are left with this, we need to sort lowest for that is lower than sw_index (right of 2)
52(41)
5214, which is the final number

IF the order is not violated at all, 
5421, then this is already the largest permutation
we just need to reverse it to 1245, to find the smallest permut

we need to becareful with 0s though (4210), flipped is (0124), need to remove all zeros in front.

* 
*/
int solve(int n) {
    if (n == 0) return 0;
    string a = to_string(n);
    int sz = a.size();
    vector<int> num(a.size(), 0);
    for (int i = 0; i < sz; ++i) {
        num[i] = a[i] - '0';
    }

    int sw_idx = -1;
    for (int i = sz - 2; i >= 0; --i) {
        if (num[i] < num[i + 1]) {
            int cand = i + 1;
            for (int j = i; j < sz; ++j) {
                if (num[i] >= num[j]) {
                    continue;
                }
                if (num[j] < num[cand]) {
                    cand = j;
                }
            }
            swap(num[i], num[cand]);
            sw_idx = i;
            break;
        }
    }

    if (sw_idx == -1) {
        reverse(a.begin(), a.end());
        return stoi(a);
    }
    else {
        sort(num.begin() + sw_idx+1, num.end());
        //reverse(num.begin() + sw_idx+1, num.end());
        string pp = "";
        for (int i = 0; i < sz; ++i) {
            pp += to_string(num[i]);
        }
        return stoi(pp);
    }

}


int main() {

  /*  int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/ 

    cout << solve(5142);


    return 0;
}