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

int handleCase1(int i, int j, vector<int> &num, vector<vector<int>> &lookup, unordered_set<int> &traversedIndex, vector<string> &lines){
  if( traversedIndex.find(lookup[i][j]) == traversedIndex.end() && lookup[i][j] != -1) {
    traversedIndex.insert(lookup[i][j]); 
    return num[lookup[i][j]];
  }
  return 0;
}

int handleCase2(int i, int j, vector<int> &num, vector<vector<int>> &lookup, unordered_set<int> &traversedIndex, vector<string> &lines, int &find){
  if( traversedIndex.find(lookup[i][j]) == traversedIndex.end() && lookup[i][j] != -1) {
    traversedIndex.insert(lookup[i][j]); 
    find += 1;
    cout << num[lookup[i][j]] << endl; 
    return num[lookup[i][j]];
  }
  return 1;
}

int main() {
  vector<string> lines = readFile("AOC-2023-03.input");
  vector<int> num;
  vector<vector<int>> lookup(lines.size(), vector<int>(lines[0].size(), -1));

  int index = 0;
  for(int i = 0; i < lines.size(); ++i) {
    string currNum = "";
    for(int j = 0; j < lines[i].size(); ++j) {
      if(lines[i][j] >= '0' && lines[i][j] <= '9') {
        currNum += lines[i][j];
        lookup[i][j] = index;
      } else if(currNum != "") {
        num.push_back(stoi(currNum));
        currNum = "";
        index++;
      }
    }
    if(currNum != "") {
      num.push_back(stoi(currNum));
      currNum = "";
      index++;
    }
  }
  
  int allSum = 0;
  unordered_set<int> traversedIndex;
  for(int i = 0; i < lines.size(); ++i) {
    for(int j = 0; j < lines[i].size(); ++j) {
      //bool isSymbol = !((lines[i][j] >= '0' && lines[i][j] <= '9') || lines[i][j] == '.');
      bool isSymbol = lines[i][j] == '*';
      if( !isSymbol ) {
        continue;
      }
      int find = 0;
      int mult = 1;
      // +
      if(i-1 >= 0) 
        mult *= handleCase2(i-1,j,num,lookup,traversedIndex, lines, find);
      if(j-1 >= 0) 
        mult *= handleCase2(i,j-1,num,lookup,traversedIndex, lines, find);
      if(i+1 < lines.size())
        mult *= handleCase2(i+1,j,num,lookup,traversedIndex, lines, find);
      if(j+1 < lines[0].size()) 
        mult *= handleCase2(i,j+1,num,lookup,traversedIndex, lines, find);

      //x
      if(i-1 >= 0 && j-1 >= 0) 
        mult *= handleCase2(i-1,j-1,num,lookup,traversedIndex, lines, find);
      if(i-1 >= 0 && j+1 < lines[0].size()) 
        mult *= handleCase2(i-1,j+1,num,lookup,traversedIndex, lines, find);
      if(i+1 < lines.size() && j-1 >= 0) 
        mult *= handleCase2(i+1,j-1,num,lookup,traversedIndex, lines, find);
      if(i+1 < lines.size() && j+1 < lines[0].size()) 
        mult *= handleCase2(i+1,j+1,num,lookup,traversedIndex, lines, find);

      if(find == 2) {
        allSum += mult;
      }
    }
  }

  cout << "sum: " << allSum << endl;

  return 0;
}