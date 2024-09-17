#include <bits/stdc++.h>
#include <cstdlib>
#include <utility>
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
  int n, count = 0;
  cin >> n;
  vector<pair<int, int>> vec(n);
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first >> vec[i].second;
  }
  for (int i = 1; i < n - 1; i++) {
    if (vec[i].first - vec[i].second > vec[i - 1].first) {
      count++;
    } else if (vec[i].first + vec[i].second < vec[i + 1].first) {
      vec[i].first += vec[i].second;
      count++;
    }
  }
  cout << count + 2;

  return 0;
}
