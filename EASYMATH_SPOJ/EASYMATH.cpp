#include <bits/stdc++.h>
#include <vector>
#define int long long int

using namespace std;

const int mod = 1e9 + 7;
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
  return (a / gcd(a, b)) * b;
}

int numberOfDivisor(int n, int a, int d)
{
  int ans = 0, LCM;
  vector<int> num = { a, a + d, a + 2 * d, a + 3 * d, a + 4 * d };
  int m = num.size();
  for (int i = 1; i < (1 << m); i++) {
    LCM = 1;
    for (int j = 0; j < m; j++) {
      if ((i >> j) & 1) {
        LCM = lcm(LCM, num[j]);
      }
    }
    if (__builtin_popcount(i) % 2 != 0) {
      ans += n / LCM;
    }
    else {
      ans -= n / LCM;
    }
  }
  return ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int n, m, a, d, t;
  cin >> t;
  while (t--) {
    cin >> m >> n >> a >> d;
    int c =
      n - numberOfDivisor(n, a, d) - (m - numberOfDivisor(m - 1, a, d)) + 1;
    cout << c << endl;
  }

  return 0;
}
