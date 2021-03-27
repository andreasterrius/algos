#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;
#define MODL 1000000007

/*
Three sum multiplicity
Accepted, suboptimal

*/


class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> occ;
        for (int i = 0; i < arr.size(); ++i) {
            occ[arr[i]] += 1;
        }

        sort(arr.begin(), arr.end());

        ll ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            occ[arr[i]] -= 1;
            int sum = target - arr[i];
            unordered_map<int, int> this_occ;
            for (int j = i + 1; j < arr.size(); ++j) {
                this_occ[arr[j]] += 1;
                int a = arr[j];
                int other = sum - a;
                if (other < a) break;
                if (occ.find(other) == occ.end()) {
                    continue;
                }
                else {
                    ll temp = (ll) occ[other] - this_occ[other];
                    if (temp <= 0) continue;

                    ans = (ans + temp) % MODL;
                }
            }
        }
        return ans;
    }
};


int main() {

    
   /* int cas;
    cin >> cas;
    int l = cas;
    int a = 1;
    while (cas--) {
        solve(l, a);
        a += 1;
    }*/

    //solve(0);
    Solution s;
    //vector<int> arr{ 1,1,2,2,3,3,4,4,5,5 };
    //
   
    //vector<int> arr{1,1,2,2,2,2};
    vector<int> arr{0,2,0};
    cout << s.threeSumMulti(arr, 0);


    return 0;
}