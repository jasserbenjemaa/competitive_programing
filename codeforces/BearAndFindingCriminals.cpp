#include <bits/stdc++.h>
#define N 20
using namespace std;
int n, k;

int findCriminals(int m[], int n, int k) {
  int x = k - 1, y = k + 1, cnt = 0;
  if (m[k] == 1) {
    cnt++;
  }
  while (x >= 0 && y < n) {
    if (m[x] == 1 && m[x] == m[y]) {
      cnt += 2;
    }
    x--, y++;
  }
  for (; y < n; y++) {
    if (m[y] == 1) {
      cnt++;
    }
  }
  for (; x >= 0; x--) {
    if (m[x] == 1) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  cin >> n >> k;
  k--;
  int m[n];

  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }
  cout << findCriminals(m, n, k);
  return 0;
}
