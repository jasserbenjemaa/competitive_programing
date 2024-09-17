#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define N 100000

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

int main() {
  PLAY();
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  int d[101][3] = {0};
  // Initial values for day 0 (no activity on the first day)
  d[0][0] = d[0][1] = d[0][2] = 0;
  for (int i = 0; i < n; i++) {
    // If there's a contest (1 or 3), update max days of contest participation
    if (vec[i] == 1 || vec[i] == 3) {
      d[i + 1][1] = max(d[i][0], d[i][2]) + 1;
    }
    // If gym is open (2 or 3), update max days of gym attendance
    if (vec[i] == 2 || vec[i] == 3) {
      d[i + 1][2] = max(d[i][0], d[i][1]) + 1;
    }
    // If it's a rest day (0), carry over previous day's gym and contest values
    if (vec[i] == 0) {
      d[i + 1][2] = d[i][2];
      d[i + 1][1] = d[i][1];
    }
    // For rest on the i-th day, take the maximum of contest and gym from the
    // previous day
    d[i + 1][0] = max(d[i][1], d[i][2]);
  }

  cout << n - max({d[n][0], d[n][1], d[n][2]});
  return 0;
}
