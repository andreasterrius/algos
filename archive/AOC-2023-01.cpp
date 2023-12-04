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

vector<int> computeLPS(string pat) {
  vector<int> lps(pat.size());
  lps[0] = 0;
  int len = 0;
  for(int i = 1; i < pat.size(); ++i) {
    if(pat[i] == pat[len]) {
      lps[i] = lps[len]+1;
      len++;
    } else {
      if(len != 0) {
        len = lps[len-1];
        i--;
      } else {
        lps[i] = 0;
      }
    }
  }
  return lps;
}

int kmp(string word, string pat, const vector<int> &lps) {
  int left = 0;
  for(int i = 0; i < (int)word.size(); ++i) {
    if(left < pat.size() && word[i] == pat[left]) {
      left++;
    } else {
      if(left != 0){
        left = lps[left-1];
        i--;
      }
    }
    if(left == pat.size()) {
      //left = lps[left-1];
      return i-left+1; //found first occurence
    }
  }
  return -1;
}

string reverseStr(string a) {
  reverse(a.begin(), a.end());
  return a;
}

int main() {
  unordered_map<string, pair<vector<int>, char>> lps{
    {"one", {computeLPS("one"), '1'}},
    {"two", {computeLPS("two"), '2'}},
    {"three", {computeLPS("three"), '3'}},
    {"four", {computeLPS("four"), '4'}},
    {"five", {computeLPS("five"), '5'}},
    {"six", {computeLPS("six"), '6'}},
    {"seven", {computeLPS("seven"), '7'}},
    {"eight", {computeLPS("eight"), '8'}},
    {"nine", {computeLPS("nine"), '9'}},
  };
  unordered_map<string, pair<vector<int>, char>> revLps{
    {reverseStr("one"), {computeLPS(reverseStr("one")), '1'}},
    {reverseStr("two"), {computeLPS(reverseStr("two")), '2'}},
    {reverseStr("three"), {computeLPS(reverseStr("three")), '3'}},
    {reverseStr("four"), {computeLPS(reverseStr("four")), '4'}},
    {reverseStr("five"), {computeLPS(reverseStr("five")), '5'}},
    {reverseStr("six"), {computeLPS(reverseStr("six")), '6'}},
    {reverseStr("seven"), {computeLPS(reverseStr("seven")), '7'}},
    {reverseStr("eight"), {computeLPS(reverseStr("eight")), '8'}},
    {reverseStr("nine"), {computeLPS(reverseStr("nine")), '9'}},
  };;

  vector<string> lines = readFile("AOC-2023-01.input");
  int sum = 0; 
  for(int i = 0; i < lines.size(); ++i) {
      char frontResult = 0;
      int frontIndex = INT_MAX;
      for(int j = 0; j < lines[i].size(); ++j) {
        if(lines[i][j] >= '0' && lines[i][j] <= '9'){
          frontResult = lines[i][j];
          frontIndex = j;
          break;
        }
      }
      for(auto &[toFind, lpsArr] : lps) {
        int found = kmp(lines[i], toFind, lpsArr.first);
        if(found != -1 && found < frontIndex) {
          frontIndex = found;
          frontResult = lpsArr.second;
        }
      }
      
      string revLine = lines[i];
      reverse(revLine.begin(), revLine.end());
      char backResult = 0;
      int backIndex = INT_MAX;
      for(int j = 0; j < revLine.size(); ++j) {
        if(revLine[j] >= '0' && revLine[j] <= '9'){
          backIndex = j;
          backResult = revLine[j];
          break;
        }
      }
      for(auto const& [toFind, lpsArr] : revLps) {
        int found = kmp(revLine, toFind, lpsArr.first);
        if(found != -1 && found < backIndex) {
          backIndex = found;
          backResult = lpsArr.second;
        }
      }

      stringstream combine;
      combine << frontResult << backResult;
      sum += stoi(combine.str(), nullptr);
      cout << combine.str() << "\n";
  }
  cout << "sum: " << sum << endl;


  // string b = "AAACAAAAAC";
  // vector<int> k(b.size());
  // computeLPSArray(b.c_str(), b.size(), &k[0]);
  // cout << b << endl;
  // debuglist(k);
  return 0;
}

