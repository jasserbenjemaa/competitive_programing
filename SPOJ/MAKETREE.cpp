#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

list<int> *adj;
vector<bool> vis;
vector<int> ans;
int n;

void dfs(int v) {
  vis[v] = true;
  for (int u : adj[v]) {
    if (!vis[u]) {
      dfs(u);
    }
  }
  ans.push_back(v + 1);
}

void topologicalSort() {
  vis.assign(n, false);
  ans.clear();
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  reverse(ans.begin(), ans.end());
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  int m; // number of edges
  cin >> n >> m;

  adj = new list<int>[n];
  vis.resize(n);

  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v;
    for (int k = 0; k < v; k++) {
      cin >> u;
      u--;
      adj[i].push_back(u);
    }
  }

  topologicalSort();

  int p = 0;
  int parent[n + 1];
  for (int i = 0; i < n; i++) {
    parent[ans[i]] = p;
    p = ans[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << parent[i] << endl;
  }
  return 0;
}
