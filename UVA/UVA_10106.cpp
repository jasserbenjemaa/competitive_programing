#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
char IntToChar(int n) { return n + '0'; }
int CharToInt(char c) { return c - '0'; }
string multiply(string s1, int s2) {
  int carry = 0;
  reverse(s1.begin(), s1.end());
  for (int i = 0; i < s1.size(); i++) {
    int d1 = CharToInt(s1[i]);
    carry = d1 * s2 + carry;
    s1[i] = IntToChar(carry % 10);
    carry /= 10;
  }
  while (carry) {
    s1.push_back(IntToChar(carry % 10));
    carry /= 10;
  }
  reverse(s1.begin(), s1.end());
  return s1;
}
string addNumbers(string n1, string n2) {

  if (n1.length() > n2.length()) {
    swap(n1, n2);
  }

  string result = "";
  reverse(n1.begin(), n1.end());
  reverse(n2.begin(), n2.end());

  int carry = 0;

  for (int i = 0; i < n1.length(); i++) {
    int d1 = CharToInt(n1[i]);
    int d2 = CharToInt(n2[i]);
    int sum = d1 + d2 + carry;
    int output_digit = sum % 10;
    carry = sum / 10;

    result.push_back(IntToChar(output_digit));
  }

  for (int i = n1.length(); i < n2.length(); i++) {
    int d2 = CharToInt(n2[i]);
    int sum = d2 + carry;
    int output_digit = sum % 10;
    carry = sum / 10;
    result.push_back(IntToChar(output_digit));
  }

  if (carry) {
    result.push_back('1');
  }

  reverse(result.begin(), result.end());
  return result;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  string s1, s2, s;
  while (cin >> s1) {
    s = "0";
    cin >> s2;
    for (int i = 0; i < s2.size(); i++) {
      string k = multiply(s1, CharToInt(s2[s2.length() - 1 - i]));
      for (int j = 0; j < i; j++) {
        k.push_back('0');
      }
      s = addNumbers(k, s);
    }
    if (s[0] == '0')
      // print 0 when s=0000000
      cout << '0' << endl;
    else
      cout << s << endl;
  }
  return 0;
}
