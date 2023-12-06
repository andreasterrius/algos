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

vector<string> readFile(string path) {
  vector<string> res;
  std::ifstream file(path);
  for (std::string line; std::getline(file, line); res.push_back(line));
  file.close();
  return res;
}

int main() {

  FILE* fp;
  fp = fopen("AOC-2023-04.input", "r");
  if(fp == NULL) return -1;

  vector<int> all(201, 1);
  int sum = 0;
  for(int c = 0; c < 201; ++c){
    unordered_set<int> winning;
    int caseNum;
    cout << "case: " << caseNum << " | ";
    fscanf(fp, "Card\t%d:", &caseNum);
    for(int i = 0; i < 10; ++i) {
      int k;
      fscanf(fp, "%d", &k);
      // cout << k << "w ";
      winning.insert(k);
    }
    char tok;
    fscanf(fp, " %c ", &tok);
    int copies = 1;
    for(int i = 0; i < 25; ++i) {
      int k;
      fscanf(fp, "%d", &k);
      // cout << k << "k ";
      if(winning.find(k) != winning.end()) {
        if(c+copies < 201){
          all[c+copies] = all[c+copies] + all[c];
          copies++;
        }
      }
    }
    sum += all[c];
    fscanf(fp, "\n");
    cout << endl;
  }

  cout << "sum:" << sum;

  return 0;
}