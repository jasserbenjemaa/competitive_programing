#include <bits/stdc++.h>
using namespace std;

int minDollars(int k[], int n) {
  int energy = 0, dollars = 0;
  for (int i = 0; i < n; i++) {
    if (k[i] - k[i + 1] + energy < 0) {
      dollars += k[i + 1] - k[i] - energy;
      energy = 0;
    } else {

      energy += k[i] - k[i + 1];
    }
  }
  return dollars;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  int k[n + 1];
  k[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
  }
  cout << minDollars(k, n);
  return 0;
}
