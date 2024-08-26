#include <bits/stdc++.h>
#include <csignal>
#include <cstdint>
using namespace std;
#define int long long int

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n, m, w, q;
  cin >> n >> m >> w >> q;
  string mat[n][m], k[] = {"Carrots", "Kiwis", "Grapes"};
  int x, y, t = 0;
  for (int i = 0; i < w; i++) {
    cin >> x >> y;
    x--, y--;
    mat[x][y] = "Waste";
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == "Waste")
        continue;
      if (t > 2)
        t = 0;
      mat[i][j] = k[t];
      t++;
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    x--, y--;
    cout << mat[x][y] << endl;
  }
  return 0;
}
