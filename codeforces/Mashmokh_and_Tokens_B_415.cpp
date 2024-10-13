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
  long long int n, a, b;
  cin >> n >> a >> b;
  int k[n];
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  for (int i = 0; i < n; i++) {
    long long int ans = (k[i] * a) % b;
    ans /= a;
    cout << ans << " ";
  }
}
