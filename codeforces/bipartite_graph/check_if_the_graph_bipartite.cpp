#include <bits/stdc++.h>
using namespace std;

const int N = 100005;  // Maximum number of nodes
vector<int> gr[N];     // Adjacency list
int vis[N];            // Color array (0 = unvisited, 1 or 2 = color)
bool odd_cycle = 0;    // Flag to detect odd-length cycle

// Depth-First Search function
void dfs(int cur, int par, int col) {
    vis[cur] = col;  // Color current node

    for (auto child : gr[cur]) {
        if (vis[child] == 0) {
            dfs(child, cur, 3 - col);  // Alternate color: (1 -> 2, 2 -> 1)
        }
        else if (child != par && vis[child] == col) {
            // Same color on both ends → odd-length cycle detected
            odd_cycle = 1;
        }
    }
    return;
}

// Main solving function
void solve() {
    int n, m;
    cin >> n >> m;

    // Build graph
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    // Run DFS from node 1 (assuming connected graph)
    dfs(1, 0, 1);

    // Check result
    if (odd_cycle)
        cout << "Not Bipartite\n";
    else
        cout << "Bipartite\n";
}

int main() {
ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    solve();
    return 0;
}

