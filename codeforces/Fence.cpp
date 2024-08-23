#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  n++;
  vector<int> k(n, 0), acc(n, 0);
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    acc[i] = acc[i - 1] + k[i];
  }
  int min = 0;
  for (int i = 1; i < n - m; i++) {
    if (acc[m + min] - acc[min] > acc[m + i] - acc[i]) {
      min = i;
    }
  }
  cout << min + 1;

  return 0;
}
