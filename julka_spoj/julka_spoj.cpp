#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
int to_digit(char n)
{
  return n - '0';
}
char to_char(int n)
{
  return n + '0';
}
string subtact(string s1, string s2)
{
  int carry = 0, res, size = s2.length(), d1, d2;
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  for (int i = 0; i < size; i++)
  {
    d1 = to_digit(s1[i]), d2 = to_digit(s2[i]);
    res = d1 - d2 - carry;
    if (res < 0)
    {
      s1[i] = to_char(res + 10);
      carry = 1;
    }
    else
    {
      s1[i] = to_char(res);
      carry = 0;
    }
  }

  while (carry)
  {
    d1 = to_digit(s1[size]);
    res = d1 - carry;
    if (res < 0)
    {
      s1[size] = to_char(res + 10);
      size++;
    }
    else
    {
      s1[size] = to_char(res);
      break;
    }
  }
  reverse(s1.begin(), s1.end());
  while(s1[0] == '0') s1=s1.substr(1, s1.length());
  return s1;
}

string divide(string s)
{
  int rest = 0, d, ans;
  for (int i = 0; i < s.length(); i++)
  {
    d = to_digit(s[i]);
    ans = (d + rest * 10);
    s[i] = to_char(ans / 2);
    rest = ans % 2;
  }
  while(s[0] == '0') s=s.substr(1, s.length());
  return s;
}
string add(string n1, string n2)
{

  // Make sure N2 is larger
  if (n1.length() > n2.length())
  {
    swap(n1, n2);
  }

  // Result
  string result = "";
  // Reverse
  reverse(n1.begin(), n1.end());
  reverse(n2.begin(), n2.end());

  // Add digit upto a n1.length()
  int carry = 0;

  for (int i = 0; i < n1.length(); i++)
  {
    int d1 = to_digit(n1[i]);
    int d2 = to_digit(n2[i]);
    int sum = d1 + d2 + carry;
    int output_digit = sum % 10;
    carry = sum / 10;

    result.push_back(to_char(output_digit));
  }

  for (int i = n1.length(); i < n2.length(); i++)
  {
    int d2 = to_digit(n2[i]);
    int sum = d2 + carry;
    int output_digit = sum % 10;
    carry = sum / 10;
    result.push_back(to_char(output_digit));
  }

  // Finally if a carrry is generated
  if (carry)
  {
    result.push_back('1');
  }

  // Reverse the final result
  reverse(result.begin(), result.end());
  return result;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int t=10;
  while(t--){
  string n, k;
  cin >> n >> k;
  string x = divide(subtact(n, k));
  string y = add(x, k);
  cout << y << endl
       << x<<endl;
  }
  return 0;
}
