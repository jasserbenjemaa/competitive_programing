#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#define N 100000 + 9

void PLAY() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cout << fixed << setprecision(2);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main() {
  PLAY();
  int n;
  cin >> n;
  int k[N];
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  sort(k, k + n);
  int ans = N;
  for (int i = 0; i < n; i++) {
    int f = upper_bound(k, k + n, k[i] * 2) - k;
    ans = min(ans, i + n - f);
  }
  cout << ans;

  return 0;
}
