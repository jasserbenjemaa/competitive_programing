#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long int

int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  std::cin >> n >> k;
  while (n != -1 && k != -1)
  {
    int b = n * (n - 1) / 2, h = 0.25*((k*k)-(k)-(k-1));
    if (k <= 2)
      cout << 0 << endl;
    else if (h == n)
      cout << 1 << endl;
    else
    {
      int gcd = __gcd(b, h);
      h /= gcd, b /= gcd;
      cout << (h) << "/" << (b) << endl;
    }
    cin >> n >> k;
  }

  return 0;
}
