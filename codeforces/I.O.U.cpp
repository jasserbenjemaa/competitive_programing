#include <bits/stdc++.h>
using namespace std;

#define N 10000 + 9

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

int main() {
  PLAY();
  int n, m;
  cin >> n >> m;
  int k[N] = {0};
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    k[x] -= z, k[y] += z;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (k[i] < 0)
      sum += k[i];
  }
  cout << sum * -1;
  return 0;
}
