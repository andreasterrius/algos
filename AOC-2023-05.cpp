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

struct Source {
    ull dest;
    ull source;
    ull range;
};


int main() {

//    FILE *fp;
//    fp = fopen("AOC-2023-05.input", "r");
//    if (fp == NULL) return -1;

    //parse this thing first
    vector<string> lines = readFile("AOC-2023-05.input");
    string seedLine = lines[0];
    size_t colon_pos = seedLine.find(":");
    std::string seeds_part = seedLine.substr(colon_pos + 1);

    // Using stringstream to split the string into vector of strings
    std::istringstream iss(seeds_part);
    std::vector<std::string> seeds_string_vector(std::istream_iterator<std::string>{iss},
                                                 std::istream_iterator<std::string>());
    vector<ull> seeds;
    for (const auto &seed: seeds_string_vector) {
        seeds.push_back(stoull(seed));
    }


    vector<Source> source;
    vector<vector<Source>> sources;
    for (int i = 3; i < lines.size(); ++i) {
        if (lines[i] == "") continue;
        if (lines[i].find(':') != string::npos) {
            sources.push_back(source);
            source.clear();
            continue;
        }
        ull a, b, c;
        // Using stringstream to extract integers from the string
        std::istringstream iss(lines[i]);
        iss >> a >> b >> c;
        source.push_back(Source{
                .dest = a,
                .source = b,
                .range = c,
        });
    }
    sources.push_back(source);

    ull lowest = seeds[0];
    for (int i = 0; i < seeds.size(); i += 2) {
        vector<pull> kk;
        kk.push_back(make_pair(seeds[i], seeds[i] + seeds[i + 1]));
        for (int j = 0; j < sources.size(); ++j) {
            vector<pull> next;
            for (int k = 0; k < sources[j].size(); ++k) {
                Source ss = sources[j][k];
                ull botStart = ss.source;
                ull botEnd = ss.source + ss.range;
                ull destStart = ss.dest;
                ull destEnd = ss.dest + ss.range;
                for (int w = 0; w < kk.size(); ++w) {
                    ull topStart = kk[w].first;
                    ull topEnd = kk[w].second;
                    cout << "pair:" << w << " line:" << k << " map:" << j << " | "
                         << topStart << " " << topEnd << " | "
                         << botStart << " " << botEnd << " | "
                         << destStart << " " << destEnd << endl;
                    // no intersection
                    if (topEnd < botStart || topStart > botEnd) {
                        next.push_back({topStart, topEnd});
                        cout << "no isect" << next.back().first << " " << next.back().second << endl;
                        continue;
                    }
                    // bottom fully coverst top
                    if (botStart <= topStart && topEnd <= botEnd) {
                        next.push_back({destStart + (topStart - botStart), destEnd - (botEnd - topEnd)});
                        cout << "bottom cover top" << next.back().first << " " << next.back().second  << endl;
                        continue;
                    }
                    // top fully covers bottom
                    if (topStart <= botStart && topEnd >= botEnd) {
                        next.push_back({topStart, botStart - 1});
                        cout << "top cover bottom" << next.back().first << " " << next.back().second << endl;
                        next.push_back({destStart, destEnd});
                        cout << "top cover bottom" << next.back().first << " " << next.back().second << endl;
                        next.push_back({botStart + 1, topEnd});
                        cout << "top cover bottom" << next.back().first << " " << next.back().second << endl;
                        continue;
                    }
                    if (topStart <= botStart) {
                        next.push_back({topStart, botStart - 1});
                        cout << "partial left" << next.back().first << " " << next.back().second << endl;
                        next.push_back({destStart, destStart + ss.range - (botEnd - topEnd)});
                        cout << "partial left" << next.back().first << " " << next.back().second << endl;
                        next.push_back({topEnd + 1, botEnd});
                        cout << "partial left" << next.back().first << " " << next.back().second << endl;
                        continue;
                    }
                    if (topEnd >= botEnd) {
                        next.push_back({botStart, topStart - 1});
                        cout << "partial right" << next.back().first << " " << next.back().second << endl;
                        next.push_back({destStart + topEnd - (botEnd - topStart), destEnd});
                        cout << "partial right" << next.back().first << " " << next.back().second << endl;
                        next.push_back({topEnd + 1, botEnd});
                        cout << "partial right" << next.back().first << " " << next.back().second << endl;
                        continue;
                    }
                    cout << "impossible" << "\n";
                    exit(0);
                }
                kk = next;
            }
            cout << "next: ";
            for (int pp = 0; pp < kk.size(); pp++) {
                cout << kk[pp].first << "," << kk[pp].second << " ";
                if (kk[pp].first < lowest) {
                    lowest = kk[pp].first;
                }
            }
            cout << endl;
        }
    }
    cout << "lowest:" << lowest << "\n";

    return 0;
}