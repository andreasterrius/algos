#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

typedef unsigned long long ll;
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;


class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int curr = -1;
        for(int i = 0; i < d.size(); ++i){
            string word = d[i];
            int jj = 0;
            for(int j = 0; j < s.size(); ++j){
                if(word[jj] == s[j]){
                    jj++;
                }
                if(jj == word.size()){
                    break;
                }
            }
            if(jj == word.size()-1){
                if(curr == -1){
                    cout << d[i] <<  endl;
                    curr = i;
                }
                else if(d[curr].size() < d[i].size()){
                    cout << d[i] << " " << d[curr] << endl;
                    curr = i;
                }
                else if(d[curr].size() == d[i].size()){
                    cout << d[i] << " " << d[curr] << endl;
                    if(d[i] < d[curr]){
                        curr = i;
                    }
                }
            }
        }
        return d[curr];
    }
};

int main() {

    // int cas;
    //cin >> cas;

    // while (cas--) {
    //  }
    vector<string> p{"zxc","vbn"};

    Solution s;
    cout << s.findLongestWord("apple", p);

    return 0;
}

