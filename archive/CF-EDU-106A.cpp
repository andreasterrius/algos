#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;
#define MODL 1000000007

/*
* ACCEPTED, but 1 hour because didntthe question problem properly
CF EduRound 106A
Board of 2*n cells 
k1, k2 cells on first row colored in white, the rest is in black
w white dominoes
b black dominoes

You can place a white domino (2x1) only if both cells are white
You can place a black domino (2x1) only if both cells are black

Need to place all w+b dominoes
Yes if can, No if false

w w b b
w w b b

*/

void solve(int cas){
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2;
    cin >> w >> b;
//
//    int grid[1000][1000] = { 0 };
//#define WHITE 1
//#define BLACK 0
//#define OCC 2
//
//    for (int i = 0; i < k1; ++i) {
//        grid[0][i] = WHITE;
//    }
//
//    for (int i = 0; i < k2; ++i) {
//        grid[1][i] = WHITE;
//    }
//
//    if (n == 1 && w == 0 && b == 0) {
//        cout << "YES\n";
//        return;
//    }
//    else if (n == 1) {
//        cout << "NO\n";
//        return;
//    }
//
//    // Hard clear white vertical for everything
//    int wall = 0;
//    for (int i = 0; i < n; ++i) {
//        if (grid[0][i] == WHITE && grid[1][i] == WHITE) {
//            grid[0][i] = OCC;
//            grid[1][i] = OCC;
//            wall += 1;
//        }
//    }
//
//    for (int i = 0; i < n-1; ++i) {
//        if (grid[0][i] == WHITE && grid[0][i + 1] == WHITE) {
//            grid[0][i] = OCC;
//            grid[0][i + 1] = OCC;
//            wall += 1;
//        }
//        if (grid[1][i] == WHITE && grid[1][i + 1] == WHITE) {
//            grid[1][i] = OCC;
//            grid[1][i + 1] = OCC;
//            wall += 1;
//        }
//    }
//
//    // Hard clear white vertical for everything
//    int ball = 0;
//    for (int i = 0; i < n; ++i) {
//        if (grid[0][i] == BLACK && grid[1][i] == BLACK) {
//            grid[0][i] = OCC;
//            grid[1][i] = OCC;
//            ball += 1;
//        }
//    }
//
//    for (int i = 0; i < n - 1; ++i) {
//        if (grid[0][i] == BLACK && grid[0][i + 1] == BLACK) {
//            grid[0][i] = OCC;
//            grid[0][i + 1] = OCC;
//            ball += 1;
//        }
//        if (grid[1][i] == BLACK && grid[1][i + 1] == BLACK) {
//            grid[1][i] = OCC;
//            grid[1][i + 1] = OCC;
//            ball += 1;
//        }
//    }
//
//
//    if (w <= wall && b <= ball) {
//        cout << "YES\n";
//    }
//    else {
//        cout << "NO\n";
//    }
    
    // count first 2 row alloed whites
    int w_vertical = min(k1, k2);
    int k1_hori = (k1 - w_vertical) / 2;
    int k2_hori = (k2 - w_vertical) / 2;
    int white_allowed = w_vertical + k1_hori + k2_hori;
    
    // count first 2 row allowed blacks
    int bvert_k1 = n - k1;
    int bvert_k2 = n - k2;
    int b_vertical = min(bvert_k1, bvert_k2);
    int k1_vert = (bvert_k1 - b_vertical) / 2;
    int k2_vert = (bvert_k2 - b_vertical) / 2;
    int black_allowed = b_vertical + k1_vert + k2_vert;

    // calculate everything
    if (w <= white_allowed && b <= black_allowed) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {

    
    int cas;
    cin >> cas;

    int a = 0;
    while (cas--) {
        solve(a++);
    }
    

    //solve(0);
  
    return 0;
}

/**
 2
 2 1 1 2 2
 2 1 2 0 0
 */
