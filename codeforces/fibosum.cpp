#include <bits/stdc++.h>
#include <cstdint>
#define int long long int

using namespace std;

const int mod = 1000000007;
const int32_t sz = 3;

struct Mat
{
  int m[sz][sz];
  Mat()
  {
    memset(m, 0, sizeof(m));
  }
  void identity()
  {
    for (int i = 0; i < sz; i++)
    {
      m[i][i] = 1;
    }
  }
  Mat operator*(Mat a)
  {
    Mat res;
    for (int i = 0; i < sz; i++)
    {
      for (int j = 0; j < sz; j++)
      {
        for (int k = 0; k < sz; k++)
        {
          res.m[i][j] += m[i][k] * a.m[k][j];
          res.m[i][j] %= mod;
        }
      }
    }

    return res;
  }
};

int Fibosum(int n)
{

  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;

  Mat M, I;
  I.identity();
  n -= 1;
  M.m[0][0] = M.m[0][1] = M.m[0][2] = 1;
  M.m[1][1] = M.m[1][2] = 1;
  M.m[2][1] = 1;

  while (n)
  {
    if (n & 1)
      I = I * M;
    M = M * M;
    n /= 2;
  }
  return (I.m[0][0] % mod + I.m[0][1] % mod) % mod;
}

int32_t main()
{
  int t;
  scanf("%lld", &t);

  while (t--)
  {
    int n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", (Fibosum(m) % mod - Fibosum(n - 1) % mod + mod) % mod);
  }

  return 0;
}
