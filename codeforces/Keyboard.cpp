#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
char translate(char s, string c) {
  string f = "qwertyuiopasdfghjkl;zxcvbnm,./q";
  int i = 0;
  while (s != f[i]) {
    i++;
  }
  return c == "R" ? f[i - 1] : f[i + 1];
}
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif
  string s, c;
  cin >> c >> s;
  for (int i = 0; i < s.size(); i++) {
    s[i] = translate(s[i], c);
  }
  cout << s;
  return 0;
}
