#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int subSum(int *b, int *e) {
  int s = 0;
  while (b < e) {
    s += *b;
    b++;
  }
  return s;
}
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int k[n];
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  sort(k, k + n);
  int b = subSum(k, k + n - 1), e = k[n - 1], i = 2;
  while (e <= b) {
    e += k[n - i];
    b -= k[n - i];
    i++;
  }
  cout << i - 1;

  return 0;
}
