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

/*
 LC - Maximum Points You can obtain from cards
 cardPoints [1,2,3,4,5,6,1], k = 3;


 */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<ull> left(n);
        vector<ull> right(n);
        ull leftSum = 0;
        ull rightSum = 0;
        for (int i = 0; i < n; ++i) {
            leftSum += cardPoints[i];
            rightSum += cardPoints[n-i-1];
            left[i] = leftSum;
            right[n-i-1] = rightSum;
        }

        if (k >= n)
            return leftSum;

        //  1,2,3,4,5,6,1 , 3

        ull mx = 0;
        int leftIdx = k-1;
        int rightIdx = n;
        for (int i = 0; i <= k; ++i) {
            
            ull rr = 0;
            if (rightIdx < n) {
                rr = right[rightIdx];
            }
            ull ll = 0;
            if (leftIdx >= 0) {
                ll = left[leftIdx];
            }

           //cout << leftIdx << " " << rightIdx << "\n";
           //cout << ll << " " << rr << "\n\n";

            mx = max(mx, ll + rr);
            leftIdx--;
            rightIdx--;
        }

        return mx;
    }
};


int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}
    vector<int> cardPoints{ 1,79,80,1,1,1,200,1 };

    Solution S;
    cout << S.maxScore(cardPoints, 3);

    return 0;
}
