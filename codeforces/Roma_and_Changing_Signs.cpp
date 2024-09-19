#include <bits/stdc++.h>
using namespace std;

#define N 100000

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

int n, k, sum = 0, minInt = 100000;
int a[N];

int main() {
  PLAY();
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] < 0 && k > 0)
      a[i] *= -1, k--;
    sum += a[i];
    if (a[i] < minInt)
      minInt = a[i];
  }
  if (k > 0 && k & 1) {
    sum -= 2 * minInt;
  }
  cout << sum;

  return 0;
}
