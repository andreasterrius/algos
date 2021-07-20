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
    LC - Three Equal Part - Accepted


    100010100101001
*/

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int countOnes = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 1) countOnes += 1;
        }

        if (countOnes % 3 != 0)
            return { -1, -1 };

        //find the location of the first ones
        vector<int> idx;
        int ctr = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 1) {
                if (ctr == 0)
                    idx.push_back(i);
                ctr++;
            }
            if (ctr == countOnes / 3    ) {
                ctr = 0;
            }
        }

        if (idx.empty())
            return { 0, (int)arr.size()-1 };
        if (idx.size() < 3)
            return { -1, -1 };

        //match a to c
        int a = idx[0];
        int b = idx[1];
        int c = idx[2];
        for (int i = c; i < arr.size(); ++i) {

            if (a >= idx[1]) return { -1, -1 };
            if (b >= idx[2]) return { -1, -1 };

            if (arr[a] != arr[i]) {
                return { -1, -1 };
            }
            if (arr[b] != arr[i]) {
                return { -1, -1 };
            }

            a++;
            b++;
        }

        return { a-1, b };
    }
};

int main() {    

    //vector<int> arr{ 1,0,1,1,0,1,0,0,1,0,1 };
    vector<int> arr{ 1,1,1,1,1,1 };

    Solution S;
    auto d = S.threeEqualParts(arr);
    debuglist(d);

    return 0;
}
