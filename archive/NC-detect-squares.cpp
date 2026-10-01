class CountSquares {
public:
  // x -> {y1, y2, y3}
  unordered_map<int, unordered_map<int, int>> xCoord;

  CountSquares() {}

  void add(vector<int> point) { xCoord[point[0]][point[1]]++; }

  int count(vector<int> point) {
    int ans = 0;

    int x = point[0];
    int y = point[1];

    for (auto &[y1, count] : xCoord[x]) {
      int dist = y - y1;
      if (dist == 0)
        continue;
      if (dist < 0)
        dist = -dist;

      /*
        x2y    xy    x1y

        x2y1   xy1   x1y1
      */
      int x1 = x + dist;
      int x2 = x - dist;

      // we have x, y, y1
      // check bottom left
      if (xCoord.find(x2) != xCoord.end() &&
          xCoord[x2].find(y) != xCoord[x2].end() &&
          xCoord.find(x2) != xCoord.end() &&
          xCoord[x2].find(y1) != xCoord[x2].end()) {
        ans += (xCoord[x2][y] * xCoord[x2][y1] * count);
      }
      // check bottom right
      if (xCoord.find(x1) != xCoord.end() &&
          xCoord[x1].find(y) != xCoord[x1].end() &&
          xCoord.find(x1) != xCoord.end() &&
          xCoord[x1].find(y1) != xCoord[x1].end()) {
        ans += (xCoord[x1][y] * xCoord[x1][y1] * count);
      }
    }
    return ans;
  }
};

// 1 -> [1, 2]
// 2 -> 2
