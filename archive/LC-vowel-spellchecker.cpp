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
Vowel Spellchecker
ACCEPTED

*/

struct Node {
    int upper;
    int lower;
    int wc;
};

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, int> perf;
        unordered_map<string, int> ccap;
        unordered_map<string, int> ttok;
        unordered_set<char> token{'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};

        for (int i = 0; i < wordlist.size(); ++i) {
            perf[wordlist[i]] = i;
            string cap = wordlist[i];
            string tok = wordlist[i];
            for (int j = 0; j < tok.size(); ++j) {
                if (token.find(tok[j]) != token.end()) {
                    //if found
                    tok[j] = 'a';
                }
                tok[j] = tolower(tok[j]);
                cap[j] = tolower(cap[j]);
            }

            if(ccap.find(cap) == ccap.end()) ccap[cap] = i;
            if(ttok.find(tok) == ttok.end()) ttok[tok] = i;
        }

        vector<string> ans;
        for (int i = 0; i < queries.size(); ++i) {
            string query = queries[i];
            if (perf.find(query) == perf.end()) {
                string query_cap = query;
                string query_tok = query;
                for (int j = 0; j < query.size(); ++j) {
                    if (token.find(query_tok[j]) != token.end()) {
                        //if found
                        query_tok[j] = 'a';
                    }
                    query_tok[j] = tolower(query_tok[j]);
                    query_cap[j] = tolower(query_cap[j]);
                }

                if (ccap.find(query_cap) != ccap.end()) {
                    ans.push_back(wordlist[ccap[query_cap]]);
                }
                else if (ttok.find(query_tok) != ttok.end()) {
                    ans.push_back(wordlist[ttok[query_tok]]);
                }
                else {
                    ans.push_back("");
                }
            }
            else {
                ans.push_back(wordlist[perf[query]]);
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
    vector<string> wordlist{ "KiTe","kite","hare","Hare" };
    vector<string> queries{ "kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto" };
    auto k =  s.spellchecker(wordlist, queries);
    for (auto &kk : k) {
        cout << kk << "\n";
    }

    return 0;
}