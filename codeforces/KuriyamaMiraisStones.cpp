#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
using namespace std;
#define int long long int

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  n++;
  vector<int> arr(n, 0), acc(n), sortArr(n, 0), accSortArr(n);
  for (int i = 1; i < n; i++) {
    cin >> arr[i];
    sortArr[i] = arr[i];
    acc[i] += acc[i - 1] + arr[i];
  }
  sort(sortArr.begin(), sortArr.end());
  for (int i = 1; i < n; i++) {
    accSortArr[i] += accSortArr[i - 1] + sortArr[i];
  }
  int m, c, l, r;
  cin >> m;
  while (m--) {
    cin >> c >> l >> r;
    if (c == 2) {
      cout << accSortArr[r] - accSortArr[l - 1];
    } else {
      cout << acc[r] - acc[l - 1];
    }
    cout << endl;
  }

  return 0;
}
