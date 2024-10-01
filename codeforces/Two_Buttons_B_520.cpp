#include <bits/stdc++.h>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

#define N 10000 + 9

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
int n, m;
int visited[N];
int dfs() {
  queue<pair<int, int>> que;
  que.push({n, 0});
  while (!que.empty()) {
    int curr = que.front().first;
    int count = que.front().second;
    que.pop();
    if (curr == m) {
      return count;
    }
    if (curr >= 0 && curr < N && visited[curr] == 0) {
      que.push({curr - 1, count + 1});
      que.push({2 * curr, count + 1});
      visited[curr] = 1;
    }
  }

  return 1000000;
}

int main() {
  PLAY();
  cin >> n >> m;
  memset(visited, 0, N);
  cout << dfs();
  return 0;
}
