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
LC - Advantage Count
Accepted
*/


class Solution {
public:
 
    // A = [2,7,11,15], 
    // B = [1,4,10,11]
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {

        vector<pair<int, int>> Bs(A.size());
        for (int i = 0; i < A.size(); ++i) {
            Bs[i] = { B[i], i };
        }
        sort(A.begin(), A.end());
        sort(Bs.begin(), Bs.end());

        vector<int> C(A.size(), -1);
        vector<int> unused;
       
        int a = 0;
        for (int i = 0; i < B.size(); ++i) {
            auto [bval, bidx] = Bs[i];
            int val = A[a];
           // cout << bval << " val \n";
            while (a < B.size()) {
                val = A[a];
                if (bval < val) {
                  //  cout << bval << " B[i] \n";
                    C[bidx] = val;
                    a++;
                    break;
                }
                else {
                    unused.push_back(val);
                }
                a++;
            }
            if (a >= B.size()) break;
        }

        for (int i = 0; i < C.size(); ++i) {
            if (C[i] == -1) {
                C[i] = unused.back();
                unused.pop_back();
            }
        }

        return C;
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
    /*vector<int> A{12,24,8,32};
    vector<int> B{13,25,32,11};*/

    //[2,7,11,15], B = [1,10,4,11]
    vector<int> A{ 2,7,11,15 };
    vector<int> B{ 1,10,4,11 };

    auto k = s.advantageCount(A, B);
    debuglist(k);


    return 0;
}