#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  string s;
  cin >> s;
  if (s.size() == 1) {
    cout << s + s;
  } else {
    string r = s;
    reverse(s.begin(), s.end());
    s = r + s;
    cout << s;
  }
  return 0;
}
