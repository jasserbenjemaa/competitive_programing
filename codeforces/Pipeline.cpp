#include <bits/stdc++.h>
using namespace std;

#define int long long int
int sum(int n) { return ((n + 1) * n) / 2; }
int subSum(int n, int k) {
  if (k <= 1)
    return sum(n);
  return sum(n) - sum(k - 1);
}
int BS_Pipeline(int n, int k) {
  int s = 1, e = k;
  while (s < e) {
    int mid = (s + e) / 2;
    int sum = subSum(k, mid);
    if (sum == n) {
      return k - mid + 1;
    }
    if (sum > n) {
      s = mid + 1;
    } else {
      e = mid;
    }
  }
  return k - s + 2;
}

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n, k;
  cin >> n >> k;
  if (n == 1)
    cout << "0" << endl;
  if (n <= k) {
    cout << 1 << endl;
  } else if (sum(k - 1) + 1 < n) {
    cout << -1 << endl;
  } else {
    k--;
    n--;
    cout << BS_Pipeline(n, k);
  }

  return 0;
}
