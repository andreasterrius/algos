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
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull, ull> pull;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
                for(int _j = 0; _j < y; ++_j) \
                    cout << arr[_i][_j] << " "; \
                cout << "\n"; }
#define MODL 1000000007

vector<string> readFile(string path) {
    vector<string> res;
    std::ifstream file(path);
    for (std::string line; std::getline(file, line); res.push_back(line));
    file.close();
    return res;
}

void extractValues(const std::string &input, std::string &A, std::string &B, std::string &C) {
    // Find the position of the opening and closing parentheses
    size_t openPos = input.find('=');
    size_t openParenthesisPos = input.find('(');
    size_t closeParenthesisPos = input.find(')');

    // Check if all positions are found
    if (openPos != std::string::npos && openParenthesisPos != std::string::npos &&
        closeParenthesisPos != std::string::npos) {

        // Extract A, B, and C from the input string
        A = input.substr(0, openPos);
        B = input.substr(openParenthesisPos + 1, closeParenthesisPos - openParenthesisPos - 1);

        // Create a stringstream from B to extract individual values
        std::istringstream iss(B);

        // Extract values separated by commas
        std::getline(iss, B, ',');
        std::getline(iss, C, ',');

        // Trim leading and trailing whitespaces
        A.erase(0, A.find_first_not_of(" "));
        A.erase(A.find_last_not_of(" ") + 1);
        B.erase(0, B.find_first_not_of(" "));
        B.erase(B.find_last_not_of(" ") + 1);
        C.erase(0, C.find_first_not_of(" "));
        C.erase(C.find_last_not_of(" ") + 1);
    } else {
        std::cerr << "Error: Positions not found in the input string." << std::endl;
    }
}


int main() {
    vector<string> lines = readFile("AOC-2023-08.input");

    string leftRight = lines[0];
    unordered_map<string, pair<string, string>> mapping;
    vector<string> currs;
    for (int i = 2; i < lines.size(); ++i) {
        string source, left, right;
        extractValues(lines[i], source, left, right);
        mapping[source] = make_pair(left, right);
        if (source[2] == 'A') currs.push_back(source);
    }

    cout <<(ull)

    for (int aa = 0; aa < currs.size(); ++aa) {
        int steps = 0;
        int stepsBefore = 0;
        string curr = currs[aa];
        int zFound = 0;
        for (int i = 0; true; ++i) {
            int idx = i % leftRight.size();
            if (leftRight[idx] == 'L') {
                curr = mapping[curr].first;
            } else {
                curr = mapping[curr].second;
            }
            steps++;
            if (curr[2] == 'Z') {
                zFound++;
                cout << aa << " steps: " << steps << " delta:" << steps - stepsBefore << endl;
                stepsBefore = steps;
                if (zFound == 5) {
                    break;
                }
            }
            if (curr == "") {
                cout << "impossible";
                break;
            }
        }
    }

//    debuglist(time);
//    debuglist(distance);

    return 0;
}