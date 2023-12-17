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
#include <chrono>

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

vector<string> templ;
vector<vector<int>> score;
vector<vector<char>> simplified;
bool found = false;

int dfs(int i, int j, bool fromLeft, bool fromRight, bool fromTop,
        bool fromBot, int startI, int startJ, int currScore) {
    bool openLeft = false;
    bool openRight = false;
    bool openTop = false;
    bool openBot = false;

    if (i == startI && j == startJ && currScore != 0) {
        found = true;
        simplified[i][j] = templ[i][j];
        return currScore;
    }
    if (score[i][j] != 0)
        return 0;

    score[i][j] = currScore;
    char curr = templ[i][j];
    if (curr == '-') {
        if (fromLeft) openRight = true;
        if (fromRight) openLeft = true;
    } else if (curr == '|') {
        if (fromTop) openBot = true;
        if (fromBot) openTop = true;
    } else if (curr == 'L') {
        if (fromTop) openRight = true;
        if (fromRight) openTop = true;
    } else if (curr == 'J') {
        if (fromTop) openLeft = true;
        if (fromLeft) openTop = true;
    } else if (curr == '7') {
        if (fromBot) openLeft = true;
        if (fromLeft) openBot = true;
    } else if (curr == 'F') {
        if (fromRight) openBot = true;
        if (fromBot) openRight = true;
    }

    int s = 0;
    if (openRight && j + 1 < templ[0].size()) {
        s = dfs(i, j + 1, true, false, false, false, startI, startJ, currScore + 1);
    }
    else if (openLeft && j - 1 >= 0) {
        s = dfs(i, j - 1, false, true, false, false, startI, startJ, currScore + 1);
    }
    else if (openTop && i - 1 < templ.size()) {
        s = dfs(i - 1, j, false, false, false, true, startI, startJ, currScore + 1);
    }
    else if (openBot && i + 1 >= 0) {
        s = dfs(i + 1, j, false, false, true, false, startI, startJ, currScore + 1);
    }
    if(found) {
        //cout << "path:" << i << " " << j << " " << simplified[i][j] << endl;
        simplified[i][j] = templ[i][j];
    }

    return s;
}

int main() {
    templ = readFile("AOC-2023-10.input");
    int startI, startJ;
    for (int i = 0; i < templ.size(); ++i) {
        //debuglist(templ[i]);
        for (int j = 0; j < templ[i].size(); ++j) {
            if (templ[i][j] == 'S') {
                startI = i;
                startJ = j;
                break;
            }
        }
    }

    string b = "|-LJ7F";
    int mmax = 0;
    vector<vector<char>> localSim;
    for (int i = 0; i < b.size(); ++i) {
        score = vector<vector<int>> {templ.size(), vector<int>(templ[0].size(), 0)};
        simplified = vector<vector<char>> { templ.size(), vector<char>(templ[0].size(), '.')};
        templ[startI][startJ] = b[i];
        int ss = dfs(startI, startJ, true, true, true, true, startI, startJ, 0);
        if(ss > mmax) {
            mmax = ss;
            localSim = simplified;
        }
    }
    simplified = localSim;
    cout << mmax / 2 << endl;

    unordered_set<char> checkedToken = {'-', 'F', 'J', 'L', '7'};

    int howMany = 0;
    for(int i = 0; i < simplified[0].size(); ++i) {;
        int thisRow = 0;
        char lastFound = '_';
        for(int j = 0; j < simplified.size(); ++j) {
            if(checkedToken.find(simplified[j][i]) != checkedToken.end()) {
                if(lastFound == '7' && simplified[j][i] != '|' && simplified[j][i] == 'L') {}
                else if(lastFound == 'F' && simplified[j][i] != '|' && simplified[j][i] == 'J') {}
                else {
                    thisRow++;
                }
                if(simplified[j][i] == '7' || simplified[j][i] == 'F') {
                    lastFound = simplified[j][i];
                }
            } else if(simplified[j][i] == '.' && (thisRow % 2) == 1) {
                howMany += 1;
                simplified[j][i] = 'X';
            }
        }
    }

    for(int i = 0; i < simplified.size(); ++i) {
        debuglist(simplified[i]);
    }

    std::cout << "howMany: " << howMany << endl;

    return 0;
}