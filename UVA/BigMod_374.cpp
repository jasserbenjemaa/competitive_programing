#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
using namespace std;
#define int long long int
int b, p, m;
int bigMod() {
  int n = 1;
  while (p) {
    if (p & 1)
      n = (n * b) % m;
    b = (b * b) % m;
    p /= 2;
  }
  return n;
}

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  while (cin >> b >> p >> m) {
    cout << bigMod() << endl;
  }

  return 0;
}
