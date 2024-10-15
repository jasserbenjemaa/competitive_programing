#include <algorithm>
#include <bits/stdc++.h>
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

int main() {
  PLAY();
  int n, curr, next, longest = 1;
  int prev = -1, countCurr = 1, countPrev = 0;
  cin >> n;
  cin >> curr;
  for (int i = 0; i < n - 1; i++) {
    cin >> next;
    if (curr == next) {
      countCurr++;
    } else if (next == prev) {
      countPrev += countCurr;
      curr = prev;
      curr = next;
      countCurr = 1;
    } else {
      longest = max(longest, countPrev + countCurr);
      prev = curr;
      curr = next;
      countPrev = countCurr;
      countCurr = 1;
    }
  }
  cout << max(longest, countCurr + countPrev);
}
