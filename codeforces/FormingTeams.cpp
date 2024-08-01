#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

#define PATH 0
#define CYCLE 1
vector<int> visited;

class Graph {
  list<int> *l;
  int V;

public:
  Graph(int v) {
    V = v;
    l = new list<int>[V];
  }
  void addEdge(int x, int y) {
    l[x].push_back(y);
    l[y].push_back(x);
  }
  list<int> *getList() { return l; }
};

int dfs(list<int> *l, int curr_node, int par_node, int &cnt_nodes) {
  if (visited[curr_node]) {
    return CYCLE;
  }
  visited[curr_node] = 1;
  cnt_nodes++;
  for (auto children : l[curr_node]) {
    if (children != par_node) {
      if (dfs(l, children, curr_node, cnt_nodes) == CYCLE) {
        return CYCLE;
      }
    }
  }
  return PATH;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n, m, x, y, exclu = 0;
  cin >> n >> m;
  Graph g(n);
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    --x, --y;
    g.addEdge(x, y);
  }
  visited = vector<int>(n);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      int cnt_nodes = 0;
      if (dfs(g.getList(), i, -1, cnt_nodes) == CYCLE) {
        exclu += cnt_nodes % 2;
      }
    }
  }
  if ((n - exclu) % 2) {
    exclu++;
  }

  cout << exclu;
  return 0;
}
