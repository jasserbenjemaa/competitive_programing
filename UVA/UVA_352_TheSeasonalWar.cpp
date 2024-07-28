#include <cstdio>
#include <iostream>
using namespace std;

#define N 30

int dx[] = {1, 0, 1, 1, 0, -1, -1, -1};
int dy[] = {0, -1, 1, -1, 1, -1, 1, 0};
void dfs(char M[N][N], int n, int i, int j, int visited[N][N]) {
  if (visited[i][j]) {
    return;
  }
  visited[i][j] = 1;
  for (int k = 0; k < 8; k++) {
    int ni = i + dx[k];
    int nj = j + dy[k];
    if (ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj] &&
        M[ni][nj] == '1') {
      dfs(M, n, ni, nj, visited);
    }
  }
}

int main(int argc, char *argv[]) {
  int n;
  char M[N][N];

  int count = 1;
  while (scanf("%d", &n) != EOF) {
    int visited[N][N] = {0};
    int s = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> M[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (M[i][j] == '1' && !visited[i][j]) {
          dfs(M, n, i, j, visited);
          s++;
        }
      }
    }
    printf("Image number %d contains %d war eagles.\n", count++, s);
  }
  return 0;
}
