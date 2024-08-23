#include <bits/stdc++.h>
#include <set>
#define N 100
using namespace std;
int r, c;
char p, m[N][N];
set<char> visitedColor;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool valid(int ni, int nj) {
  return ni < r && nj < c && ni >= 0 && nj >= 0 && m[ni][nj] != '.' &&
         m[ni][nj] != p;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  cin >> r >> c >> p;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> m[i][j];
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (m[i][j] == p) {
        for (int k = 0; k < 4; k++) {
          int ni = dy[k] + i, nj = dx[k] + j;
          if (valid(ni, nj)) {
            visitedColor.insert(m[ni][nj]);
          }
        }
      }
    }
  }
  cout << visitedColor.size();
  return 0;
}
