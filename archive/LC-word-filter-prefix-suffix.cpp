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
* Word Filter
* 
design a class to search words given prefix and suffix

["WordFilter","f","f","f","f","f","f","f","f","f","f"]
[[["cabaabaaaa","ccbcababac","bacaabccba","bcbbcbacaa","abcaccbcaa","accabaccaa","cabcbbbcca","ababccabcb","caccbbcbab","bccbacbcba"]],["bccbacbcba","a"],["ab","abcaccbcaa"],["a","aa"],["cabaaba","abaaaa"],["cacc","accbbcbab"],["ccbcab","bac"],["bac","cba"],["ac","accabaccaa"],["bcbb","aa"],["ccbca","cbcababac"]]
*/

class Node {
public:
    unordered_map<char, Node*> ch;

    //unordered_set<int> index;

    int largest;
};

class WordFilter {
public:

    Node *prefix;
    //Node *suffix;

    void createWord(string word, int i) {
        Node* curr = prefix;
        for (int j = 0; j < word.size(); ++j) {
            if (curr->ch.find(word[j]) == curr->ch.end()) {
                curr->ch[word[j]] = new Node();
            }
            curr->largest = max(curr->largest, i);
            //curr->index.insert(i);
            curr = curr->ch[word[j]];
            if (j == word.size() - 1) {
                curr->largest = max(curr->largest, i);
                //   curr->index.insert(i);
            }
        }
    }

    WordFilter(vector<string>& words) {
        prefix = new Node();
        //suffix = new Node();
        for (int i = 0; i < words.size(); ++i) {
            if (words.empty())
                continue;

            for (int j = 0; j < words[i].size(); ++j) {
                string word = words[i].substr(words[i].size()- 1 - j, j + 1) + "#" + words[i];
                //cout << word << " ";
                createWord(word, i);
            }

            //curr = suffix;
            //for (int j = words[i].size()-1; j >= 0; --j) {
            //    if (curr->ch.find(words[i][j]) == curr->ch.end()) {
            //        curr->ch[words[i][j]] = new Node();
            //    }
            //    curr->index.insert(i);
            //    curr = curr->ch[words[i][j]];
            //    if (j == 0) {
            //        curr->index.insert(i);
            //    }
            //}
        }
    }

    Node* traverse(Node* n, string str) {
        //cout << n->ch.size() << ": ";
        //for (auto& [k, v] : n->ch) {
        //    cout << k << " ";
        //    traverse(v, str);
        //}

        Node* curr = n;
        for (int i = 0; i < str.size(); ++i) {
            if (curr->ch.find(str[i]) == curr->ch.end()) {
                return nullptr;
            }
            curr = curr->ch[str[i]];
        }
        
        return curr;
    }

    int f(string pred, string sufd) {
        Node *pre = traverse(prefix, sufd+"#"+pred);
        
        if (pre == nullptr)
            return -1;

        return pre->largest;
    }
};


void solve(int cas) {
   
}

int main() {
    //int t = 1;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}
    vector<string> words{ "cabaabaaaa","ccbcababac","bacaabccba","bcbbcbacaa","abcaccbcaa","accabaccaa","cabcbbbcca","ababccabcb","caccbbcbab","bccbacbcba"};
    WordFilter S(words);
    
    cout << S.f("bccbacbcba", "a");
    
    return 0;
}