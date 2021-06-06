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

int parse(string d) {
    stack<int> st;

    if (d.empty()) 
        return 0;

    d.push_back('x');

    int ans = 0;
    int minus = 0;
    char lastOp = ' ';
    string num = "";
    for (int i = 0; i < d.size(); ++i) {
        if (d[i] >= '0' && d[i] <= '9') {
            num.push_back(d[i]);
        }
        else {
            if (d[i] == '(' || d[i] == ')') {
                int bracket = 1;
                int start = i;
                i++;
                while (bracket != 0) {
                    if (d[i] == '(')
                        bracket++;
                    else if (d[i] == ')')
                        bracket--;
                    i++;
                }

                string subOp = d.substr(start+1, i - start - 2);
                cout << subOp << "\n";
                num = to_string(parse(subOp));
            }

            if (num.size() != 0) {
                int n = stoi(num);
                if (minus % 2 == 1) {
                    n = -n;
                }
                if (lastOp != ' ') {
                    int temp = st.top(); st.pop();
                    if (lastOp == '*')
                        n = n * temp;
                    else
                        n = temp / n;
                }
                st.push(n);

                num = "";
                minus = 0;
                lastOp = ' ';
            }

            if (d[i] == '-')
                minus++;
            if (d[i] == '*' || d[i] == '/')
                lastOp = d[i];
        }
    }

    while (!st.empty()) {
        ans += st.top(); st.pop();
    }

    return ans;
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
    

    return 0;
}
