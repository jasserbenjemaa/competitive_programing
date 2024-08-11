#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    double res;
    cin >> k;
    res = (double)(2 * 180) / (180 - k);
    if (res == static_cast<int>(res)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
