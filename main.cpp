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

int main() {
    vector<string> lines = readFile("AOC-2023-06.input");

    string timeLine = lines[0];
    size_t colon_pos = timeLine.find(":");
    std::string timepart = timeLine.substr(colon_pos + 1);
    std::istringstream iss(timepart);
    std::vector<std::string> timepart_vec(std::istream_iterator<std::string>{iss},
                                          std::istream_iterator<std::string>());

    string distanceStr = lines[1];
    colon_pos = distanceStr.find(":");
    std::string distancepart = distanceStr.substr(colon_pos + 1);
    std::istringstream iss2(distancepart);
    std::vector<std::string> distance_vec(std::istream_iterator<std::string>{iss2},
                                          std::istream_iterator<std::string>());

    vector<ull> time;
    vector<ull> distance;
    for (int i = 0; i < timepart_vec.size(); ++i) {
        time.push_back(stoull(timepart_vec[i]));
        distance.push_back(stoull(distance_vec[i]));
    }

    ull thisWay = 1;
    for (int i = 0; i < time.size(); ++i) {
        ull thisWayLocal = 0;
        for(ull hold = 0; hold <= time[i]; ++hold){
            ull remTime = time[i]-hold;
            ull travelDist = remTime * hold;
            if(travelDist > distance[i])
                thisWayLocal += 1;
        }
        if (thisWayLocal != 0)
            thisWay = thisWay * thisWayLocal;
        cout << thisWayLocal << " ";
    }
    cout << endl;
    cout << thisWay << endl;

//    debuglist(time);
//    debuglist(distance);

    return 0;
}