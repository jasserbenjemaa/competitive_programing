#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

list<int> *adj;
vector<bool> vis;
vector<int> ans;
int n, m;

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

  while (scanf("%d %d", &n, &m) == 2) {
    adj = new list<int>[n];
    vis.resize(n);

    for (int i = 0; i < m; ++i) {
      int v, u;
      scanf("%d %d", &v, &u);
      u--, v--;
      adj[v].push_back(u);
    }

    topologicalSort();

    for (int i = 0; i < n; i++) {
      printf("%d\n", ans[i]);
    }

    delete[] adj; // Free allocated memory
  }

  return 0;
}
