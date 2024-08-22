#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <string>
#include <utility>
using namespace std;
int char_to_int(char c) { return c - '0'; }
char int_to_char(int n) { return n + '0'; }
void remove0(string &s) {
  while (s[s.size() - 1] == '0') {
    s.pop_back();
  }
}
string add(string n, string k) {
  if (n.size() < k.size())
    swap(n, k);
  int carry = 0, d;
  for (int i = 0; i < k.size(); i++) {
    int d1 = char_to_int(n[i]), d2 = char_to_int(k[i]);
    d = (d1 + d2 + carry);
    carry = d / 10;
    n[i] = int_to_char(d % 10);
  }
  int i = k.size();
  while (carry && i < n.size()) {
    int d1 = char_to_int(n[i]);
    d = (d1 + carry);
    carry = d / 10;
    n[i] = int_to_char(d % 10);
    i++;
  }
  if (carry)
    n.push_back('1');
  if (n[0] == '0') {
    reverse(n.begin(), n.end());
    remove0(n);
    reverse(n.begin(), n.end());
  }
  return n;
}
int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    string n, k;
    cin >> n >> k;
    remove0(n), remove0(k);
    cout << add(n, k) << endl;
  }
  return 0;
}
