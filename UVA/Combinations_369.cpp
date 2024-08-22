#include <cstring>
#include <iostream>
using namespace std;
#define int long long int
int k[102][102];

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n, m;
  memset(k, 0, sizeof(k));
  k[1][1] = 1;
  k[1][2] = 1;
  for (int i = 2; i < 102; i++) {
    for (int j = 1; j < 102; j++) {
      k[i][j] = k[i - 1][j - 1] + k[i - 1][j];
    }
  }
  while (cin >> n >> m && n | m) {
    printf("%lld things taken %lld at a time is %lld exactly.\n", n, m,
           k[n][m + 1]);
  }

  return 0;
}
