#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
using namespace std;
double dist(double x1, double x2, double y1, double y2) {
  return sqrt(pow((x1 - x2), 2) + pow(y1 - y2, 2));
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n, k;
  double s = 0.0;
  cin >> n >> k;
  int x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n - 1; i++) {
    s += dist(x[i], x[i + 1], y[i], y[i + 1]);
  }
  double res = s / 50 * k;
  printf("%.9f", res);
  return 0;
}
