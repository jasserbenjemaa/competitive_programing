#include <bits/stdc++.h>
#include <cmath>
#include <string>
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

int calc(string s) {
  int sum = 0;
  for (char c : s) {
    if (c == '+')
      sum++;
    else if (c == '-')
      sum--;
  }
  return sum;
}
int main() {
  PLAY();
  string s1, s2;
  int x = 0, count = 0;
  cin >> s1 >> s2;
  for (char c : s2) {
    if (c == '?')
      x++;
  }
  for (int i = 0; i < pow(2, x); i++) {
    int y = 0;
    for (int j = 0; j < x; j++) {
      if (i >> j & 1)
        y++;
      else
        y--;
    }
    if (calc(s1) == calc(s2) + y) {
      count++;
    }
  }
  printf("%.9f", (float)count / pow(2, x));
}
