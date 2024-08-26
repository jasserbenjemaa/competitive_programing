#include <algorithm>
#include <bits/stdc++.h>
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
  int n, f, s = 0;
  cin >> n >> f;
  int m[n];
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    s += min(x, y);
    m[i] = min(2 * x, y) - min(x, y);
  }
  sort(m, m + n, greater<int>());
  for (int i = 0; i < f; i++) {
    s += m[i];
  }
  cout << s;

  return 0;
}
