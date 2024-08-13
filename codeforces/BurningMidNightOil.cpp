#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int geoSum(int n, int k, int mid) {
  int sum = 0, i = 0, value = mid / pow(k, i);
  while (sum <= n && value != 0) {
    sum += value;
    i++;
    value = mid / pow(k, i);
  }
  return sum;
}

int LinesNumbers(int n, int k) {
  int st = 1, en = n;
  while (st <= en) {
    int mid = st + (en - st) / 2;
    int sum = geoSum(n, k, mid);
    if (sum == n) {
      return mid;
    }
    if (sum < n) {
      st = mid + 1;
    } else {
      en = mid - 1;
    }
  }
  return st;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n, k;
  cin >> n >> k;
  if (n <= 2) {
    cout << n;
  } else {
    cout << LinesNumbers(n, k);
  }
  return 0;
}
