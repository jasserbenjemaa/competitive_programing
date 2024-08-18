#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
string s;
int n;
string decode() {

  string copy = s;
  int x = 0, y = 1;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      copy[n / 2 - y] = s[i];
      y++;
    } else {
      copy[n / 2 + x] = s[i];
      x++;
    }
  }
  if (!(n & 1)) {
    reverse(copy.begin(), copy.end());
  }

  return copy;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  cin >> n >> s;
  cout << decode();

  return 0;
}
