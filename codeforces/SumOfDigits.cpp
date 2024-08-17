#include <bits/stdc++.h>
#define N 20
using namespace std;
int char_to_int(char c) { return c - '0'; };
char int_to_char(int n) { return n + '0'; }
int sumDigit(string s) {
  int sum = 0, cnt = 0;
  while (s.size() > 1) {

    for (int i = 0; i < s.size(); i++) {
      sum += char_to_int(s[i]);
    }
    s = "";
    while (sum != 0) {
      char d = int_to_char(sum % 10);
      sum /= 10;
      s.push_back(d);
    }
    cnt++;
  }
  return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  string s;
  cin >> s;
  cout << sumDigit(s);
  return 0;
}
