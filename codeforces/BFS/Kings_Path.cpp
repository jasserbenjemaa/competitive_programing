#include <bits/stdc++.h>
using namespace std;

#define N 100000

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

set<pair<int, int>> allowed;
struct Point {
  int x, y;
  bool operator<(const Point &other) const {
    return tie(x, y) < tie(other.x, other.y);
  }
};

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
Point source, destination;
int n;

bool validMove(int y, int x) {
  return y <= 1e9 && x <= 1e9 && y >= 1 && x >= 1 && allowed.count({y, x});
}

int BFS() {
  queue<pair<Point, int>> q;
  map<Point, bool> visited;
  q.push({source, 0});
  visited[source] = 1;

  while (!q.empty()) {
    int x = q.front().first.x, y = q.front().first.y;
    int distance = q.front().second;
    q.pop();

    if (x == destination.x && y == destination.y) {
      return distance;
    }
    for (int v = 0; v < 8; ++v) {
      int ny = y + dy[v];
      int nx = x + dx[v];
      Point npts = {nx, ny};
      if (validMove(ny, nx) && !visited[npts]) {
        q.push({npts, distance + 1});
        visited[npts] = 1;
      }
    }
  }
  return -1;
}

int main() {
  PLAY();
  cin >> source.y >> source.x;
  cin >> destination.y >> destination.x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int r, a, b;
    cin >> r >> a >> b;
    for (int j = a; j <= b; j++)
      allowed.insert({r, j});
  }
  cout << BFS();
  return 0;
}
