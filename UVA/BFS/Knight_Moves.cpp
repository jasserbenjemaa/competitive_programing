#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;
void PLAY() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  cout << fixed << setprecision(2);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

struct Point {
  int x, y;
};

int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};
bool validMove(int i, int j) { return i < 8 && j < 8 && i >= 0 && j >= 0; }

int bfsShortPath(Point source, Point distination) {
  int i = source.y, j = source.x;
  bool visited[8][8]{false};
  int dist[8][8]{0};
  queue<Point> que;
  vector<int> distance;
  que.push({j, i});
  visited[i][j] = true;
  dist[i][j] = 0;
  while (!que.empty()) {
    Point p = que.front();
    que.pop();
    if (p.y == distination.y && p.x == distination.x) {
      return dist[p.y][p.x];
    }
    for (int k = 0; k < 8; k++) {
      int ni = p.y + dy[k];
      int nj = p.x + dx[k];
      if (validMove(ni, nj) && !visited[ni][nj]) {
        que.push({nj, ni});
        dist[ni][nj] = dist[p.y][p.x] + 1;
        visited[ni][nj] = true;
      }
    }
  }
  return 0;
}
Point getPoint(string s) {
  Point p;
  p.y = s[1] - '1';
  p.x = s[0] - 'a';
  return p;
}

int main() {
  PLAY();
  string s, d;
  while (cin >> s >> d) {
    if (s == d) {
      cout << "To get from " << s << " to " << d << " takes 0 knight moves."
           << endl;
      continue;
    }
    Point distination, source;
    distination = getPoint(d);
    source = getPoint(s);
    int ans = bfsShortPath(source, distination);
    cout << "To get from " << s << " to " << d << " takes " << ans
         << " knight moves." << endl;
  }

  return 0;
}
