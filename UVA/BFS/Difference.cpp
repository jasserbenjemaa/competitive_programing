#include <bits/stdc++.h>
#include <list>
#include <queue>
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
int sumVector(vector<int> arr) {
  int sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
  }
  return sum;
}
int minBFS(list<int> *l, int i, int u, vector<int> d) {
  queue<int> que;
  int sum = 0;
  vector<bool> visited(u, false);
  que.push(i);
  visited[i] = true;
  while (!que.empty()) {
    int curr = que.front();
    que.pop();
    for (auto node : l[curr]) {
      if (!visited[node]) {
        visited[node] = true;
        que.push(node);
        sum += d[node];
      }
    }
  }
  return sum;
}

int maxBFS(list<int> *l, int i, int u, vector<int> d) {
  queue<int> que;
  int sum = sumVector(d) - d[i];
  vector<bool> visited(u, false);
  que.push(i);
  visited[i] = true;
  while (!que.empty()) {
    int curr = que.front();
    que.pop();
    for (auto node : l[curr]) {
      if (!visited[node]) {
        visited[node] = true;
        que.push(node);
        sum -= d[node];
      }
    }
  }
  return sum;
}
int main() {
  PLAY();
  int u, v;
  int caseNumber = 1;
  while (cin >> u >> v && u != 0) {

    vector<int> d(u);
    list<int> *lmin = new list<int>[u];
    list<int> *lmax = new list<int>[u];
    for (int i = 0; i < u; i++) {
      cin >> d[i];
    }
    for (int i = 0; i < v; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      lmin[y].push_back(x);
      lmax[x].push_back(y);
    }
    int q, x;
    cin >> q;
    cout << "Case #" << caseNumber++ << ":" << endl;
    while (q--) {
      cin >> x;
      x--;
      int res = maxBFS(lmax, x, u, d) - minBFS(lmin, x, u, d);
      cout << res << endl;
    }
    cout << endl;
  }
  return 0;
}
