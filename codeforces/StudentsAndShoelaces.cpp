#include <bits/stdc++.h>
#include <list>
#include <queue>
using namespace std;

void PLAY() {
#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif
  cout << fixed << setprecision(2);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main() {
  PLAY();
  int n, m;
  cin >> n >> m;
  list<int> *l = new list<int>[n];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    l[x].push_back(y);
    l[y].push_back(x);
  }
  queue<pair<int, int>> que;
  bool ok = true;
  int count = 0;
  while (ok) {
    ok = false;
    for (int i = 0; i < n; i++) {
      if (l[i].size() == 1) {
        que.push({i, l[i].front()});
      }
    }
    if (!que.empty()) {
      count++;
      ok = true;
    }
    while (!que.empty()) {
      int current1 = que.front().first;
      int current2 = que.front().second;
      que.pop();
      l[current1].remove(current2);
      l[current2].remove(current1);
    }
  }
  cout << count;

  return 0;
}
