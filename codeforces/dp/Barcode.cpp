#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define N 1000000

void PLAY() {
#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif
  cout << fixed << setprecision(2);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n, m, x, y;
int dotNumbers[N + 9];
int mem[1000 + 9][1000 + 9][3];
int barcod(int col, int wid, int last) {
  if (col == m) {
    if (wid < x || wid > y) {
      return 1000000;
    }
    return 0;
  }
  int &ans = mem[col][wid][last];
  if (ans != -1) {
    return ans;
  }
  int dots = 1000000;
  if (col == 0 || (last == 0 && wid + 1 <= y) || (last == 1 && wid >= x)) {
    dots = n - dotNumbers[col] + barcod(col + 1, (last == 0) ? wid + 1 : 1, 0);
  }

  int hashs = 1000000;
  if (col == 0 || (last == 1 && wid + 1 <= y) || (last == 0 && wid >= x)) {
    hashs = dotNumbers[col] + barcod(col + 1, (last == 1) ? wid + 1 : 1, 1);
  }

  return ans = min(dots, hashs);
}

int main() {
  PLAY();
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '.')
        dotNumbers[j]++;
    }
  }
  memset(mem, -1, sizeof(mem));
  cout << barcod(0, 0, 2);
  return 0;
}
