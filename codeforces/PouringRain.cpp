#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#define M_PI 3.14159265358979323846
using namespace std;
double cylinderVol(int d, int h) {
  return M_PI * pow(d * 1.0 / 2, 2) * h * 1.0;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int d, h, v, e;
  cin >> d >> h >> v >> e;
  double V = cylinderVol(d, h), E = cylinderVol(d, e), res;
  res = V / (v - E);
  if (res < 0) {
    cout << "NO";
  } else {

    cout << "YES" << '\n' << res << endl;
  }

  return 0;
}
