#include <iostream>
#include <vector>
#include <map>
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

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_set<int> g;
        int secondLowest = INT_MAX;
        int lowest = INT_MAX;;
        
        bool all_same = true;
        int same = arr[0];
        for(int i = 0; i < arr.size(); ++i){
            g.insert(arr[i]);
            if(arr[i] < lowest) {
                secondLowest = lowest;
                lowest = arr[i];
            }
            if(arr[i] <= secondLowest && arr[i] > lowest){
                secondLowest = arr[i];
            }
            
            if (same != arr[i]){
                all_same = false;
            }
        }
        
        if(all_same) return true;
        
        int diff = abs(lowest - secondLowest);

        //cout << lowest << " " << diff << endl;
        
        int curr = lowest;
        for(int i = 0; i < arr.size()-1; ++i){
            curr = curr + diff;
            //cout << curr << endl;
            if(g.find(curr) == g.end()){
                return false;
            }
        }

        return true;
    }
};

//3, 5, 1

int main() {    

    Solution S;
    vector<int> arr {
        3, 5, 1
    };

    S.canMakeArithmeticProgression(arr);

    return 0;
}

//1 1 2 3 