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

/*
 * High = No more
 * Pair =
 *      None + 2 J
 *      High + 1 J
 * TwoPair = Never
 * ThreeOfAKind =
 *      None + 3 J
 *      High + 2 J
 *      Pair + 1 J
 * FullHouse =
 *      TwoPair + 1 J
 * FourOfAKind =
 *      None + 4 J
 *      High + 3 J
 *      Pair + 2 J
 *      ThreeOfAKind + 1 J
 * FiveOfAKind =
 *      None + 5 J
 *      High + 4 J
 *
 * */

enum HandType {
    None = 0,
    High,
    Pair,
    TwoPair,
    ThreeOfAKind,
    FullHouse,
    FourOfAKind,
    FiveOfAKind,
};

int getVal(char t) {
    if (t == 'A') return 100;
    else if (t == 'K') return 99;
    else if (t == 'Q') return 98;
    else if (t == 'J') return -1;
    else if (t == 'T') return 10;
    return t - '0';
}

struct Hand {
    int bid;
    HandType type;
    string cards;

    bool operator<(const Hand &other) const {
        if (this->type != other.type)
            return this->type > other.type;

        for (int i = 0; i < other.cards.size(); ++i) {
            int a = getVal(other.cards[i]);
            int b = getVal(this->cards[i]);
            if (a != b) {
                return a < b;
            }
        }
        return false;
    }
};

vector<string> readFile(string path) {
    vector<string> res;
    std::ifstream file(path);
    for (std::string line; std::getline(file, line); res.push_back(line));
    file.close();
    return res;
}

HandType determineHandType(string cards) {
    unordered_map<char, int> hand;

    int countJ = 0;
    for (int i = 0; i < cards.size(); ++i) {
        if (cards[i] == 'J') {
            countJ += 1;
            continue;
        }
        hand[cards[i]] += 1;
    }

    vector<int> count;
    for(auto &[k, v] : hand) {
        count.push_back(v);
    }
    std::sort(count.begin(), count.end());
    std::reverse(count.begin(), count.end());
    // LMAO, this worked somehow
    if(count.size() == 0) {
        if(countJ == 5) return FiveOfAKind;
    } else if(count.size() == 1) {
        if(count[0]+countJ == 5) return FiveOfAKind;
    } else if(count.size() == 2) {
        if(count[0]+countJ == 4) return FourOfAKind;
        if(count[0]+countJ == 3) return FullHouse;
    } else if(count.size() == 3) {
        if(count[0]+countJ == 3) return ThreeOfAKind;
        if(count[0]+countJ == 2) return TwoPair;
    } else if(count.size() == 4) {
        return Pair;
    } else {
        return High;
    }
}

int main() {
    vector<string> lines = readFile("AOC-2023-07.input");
    vector<Hand> hands;
    for (int i = 0; i < lines.size(); ++i) {
        std::istringstream iss(lines[i]);
        std::vector<std::string> tokens;

        do {
            std::string token;
            iss >> token;

            if (!token.empty()) {
                tokens.push_back(token);
            }
        } while (iss);

        hands.push_back(Hand{
                .bid = stoi(tokens[1]),
                .type = determineHandType(tokens[0]),
                .cards = tokens[0],
        });
    }

    int sum = 0;
    std::sort(hands.begin(), hands.end());
    std::reverse(hands.begin(), hands.end());
    for (int i = 0; i < hands.size(); ++i) {
        int rank = i + 1;
        sum += hands[i].bid * rank;
    }
    std::cout << "sum:" << sum << endl;

    return 0;
}