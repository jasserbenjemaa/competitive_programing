#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;

#define N 100
char M[N][N];
int n;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int i, int j, int visited[N][N], int &check) {
  if (visited[i][j]) {
    return;
  }
  visited[i][j] = 1;
  if (M[i][j] == 'x')
    check = 1;
  for (int k = 0; k < 4; k++) {
    int ni = i + dx[k];
    int nj = j + dy[k];
    if (ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj] &&
        M[ni][nj] != '.') {
      dfs(ni, nj, visited, check);
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int t, counter = 1;
  cin >> t;
  while (t--) {
    int visited[N][N] = {0};
    cin >> n;
    int s = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> M[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j] && M[i][j] != '.') {
          int check = 0;
          dfs(i, j, visited, check);
          s += check;
        }
      }
    }
    printf("Case %d: %d\n", counter++, s);
  }

  return 0;
}
