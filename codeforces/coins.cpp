#include <bits/stdc++.h>
#include <iostream>
#include <utility>

using namespace std;
string s = "ABC", t[3];
int pos(char c) {
  int pos = 0;
  while (s[pos] != c) {
    pos++;
  }
  return pos;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  bool repeat = true;
  int IterationLimit = 4;
  for (int i = 0; i < 3; i++) {
    cin >> t[i];
  }

  while (repeat && IterationLimit) {
    repeat = false;
    IterationLimit--;
    for (int i = 0; i < 3; i++) {
      int p1 = pos(t[i][0]), p2 = pos(t[i][2]);
      if (t[i][1] == '<') {
        if (p1 > p2) {
          swap(s[p1], s[p2]);
          repeat = true;
        }
      } else if (t[i][1] == '>') {
        if (p1 < p2) {
          swap(s[p1], s[p2]);
          repeat = true;
        }
      }
    }
  }
  if (IterationLimit != 0) {

    cout << s;
  } else {
    cout << "Impossible";
  }

  return 0;
}
