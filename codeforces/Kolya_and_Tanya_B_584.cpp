#include <bits/stdc++.h>
#include <cmath>
#include <cstdint>
using namespace std;

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
int mod = 1e9 + 7;
int power(long long a, long long n) {
  int res = 1;
  while (n) {
    if (n & 1)
      res = ((res % mod) * (a % mod)) % mod;
    a = ((a % mod) * (a % mod)) % mod;
    n /= 2;
  }
  return res;
}

int32_t main() {
  PLAY();
  long long n;
  cin >> n;
  long long ans = (power(3, n * 3) - power(7, n) + mod) % mod;
  cout << ans;
  return 0;
}
