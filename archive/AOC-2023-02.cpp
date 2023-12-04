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
  vector<string> lines = readFile("AOC-2023-02.input");
  int sum = 0;
  for(int i = 0; i < lines.size(); ++i) {
    string line = lines[i] + ';';
    int maxRed = 0;
    int maxGreen = 0;
    int maxBlue = 0;
    int red = 0;
    int green = 0;
    int blue = 0;
    
    int id;
    sscanf(line.c_str(), "Game %d", &id);
    std::size_t found = line.find(": ");

    string num = "";
    string color = "";
    for(int j = found+2; j < line.size(); ++j) {
      if(line[j] >= '0' && line[j] <= '9') {
        num += line[j];
      } 
      if(line[j] >= 'a' && line[j] <= 'z') {
        color += line[j];
      } 
      if(line[j] == ',' || line[j] == ';') {
        int inum = stoi(num);
        if(color == "red"){
          red += inum;
        } else if(color == "green") {
          green += inum;
        } else if(color == "blue") {
          blue += inum;
        }
        num = "";
        color = "";
      }
      if(line[j] == ';') {
        maxRed = max(red, maxRed);
        maxGreen = max(green, maxGreen);
        maxBlue = max(blue, maxBlue);
        red = 0;
        green = 0;
        blue = 0;
      }
    }
    int power =  maxRed * maxGreen * maxBlue; 
    sum += power;
    // cout << id << ": " << maxRed << " " << maxGreen << " " << maxBlue << " " << power << endl;  
  }
  cout << "sum:" << sum << endl;

  return 0;
}