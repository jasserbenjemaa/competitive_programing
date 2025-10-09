#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> gr[N];
int color[N];
int n, m;

bool dfs(int u, int c) {
    color[u] = c;
    for (int v : gr[u]) {
        if (color[v] == 0) {
            if (!dfs(v, 3 - c))
                return false;
        } else if (color[v] == color[u]) {
            return false; // not bipartite
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    int to_remove = 0;

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1))
                to_remove++;
        }
    }

    // if remaining students form an odd number, remove one more
    if ((n - to_remove) % 2 != 0)
        to_remove++;

    cout << to_remove << "\n";
    return 0;
}

