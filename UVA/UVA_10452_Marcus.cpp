#include <bits/stdc++.h>
using namespace std;

#define M 10
int r, c;
int dx[] = {0, -1, 0};
int dy[] = {-1, 0, 1};
string step[] = {"left", "forth", "right"};
string word = "@IEHOVA#";

void dfs(char m[M][M], int posCh, int i, int j, int visited[M][M],
         vector<string> &path) {
  if (visited[i][j]) {
    return;
  }
  if (m[i][j] == '#') {
    return;
  }
  visited[i][j] = 1;
  posCh++;
  for (int x = 0; x < 3; x++) {
    int ni = i + dx[x];
    int nj = j + dy[x];
    if (ni < r && nj < c && ni >= 0 && nj >= 0 && !visited[ni][nj] &&
        word[posCh] == m[ni][nj]) {
      path.push_back(step[x]);
      dfs(m, posCh, ni, nj, visited, path);
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    cin >> r >> c;
    char m[M][M];
    vector<string> path;
    int visited[M][M] = {0};
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> m[i][j];
      }
    }
    for (int i = 0; i < c; i++) {
      if (m[r - 1][i] == '@') {
        dfs(m, 0, r - 1, i, visited, path);
      }
    }
    for (int i = 0; i < path.size(); i++) {
      cout << path[i];
      if (i < path.size() - 1)
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}
