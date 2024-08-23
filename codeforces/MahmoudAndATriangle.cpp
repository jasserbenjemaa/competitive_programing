#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define N 100000
int n;
int k[N];
void BS_thiredSide(int j, int i, bool &found) {
  int st = j + 1, en = i - 1;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (k[mid] + k[j] > k[i]) {
      found = true;
      return;
    } else if (k[mid] + k[j] == k[i]) {
      st = st + 1;
    } else {
      st = mid + 1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  bool found = false;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  sort(k, k + n);

  for (int i = 2; i < n && !found; i++) {
    for (int j = 0; j < i - 1; j++) {
      BS_thiredSide(j, i, found);
    }
  }
  if (found)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}
