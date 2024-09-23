#include <bits/stdc++.h>
using namespace std;

#define N 1000000 + 9

void PLAY() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  cout << fixed << setprecision(2);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
#define MOD 1073741824
int mem[N];
int countDivisors(int n) {
  int cnt = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;

      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
int solve(int a, int b, int c) {
  int count = 0;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        if (mem[i * j * k] != -1) {
          count += mem[i * j * k];
          continue;
        }
        count += countDivisors(i * k * j) % MOD;
        mem[i * k * j] = countDivisors(i * k * j) % MOD;
      }
    }
  }

  return count % MOD;
}

int main() {
  PLAY();
  int a, b, c;
  cin >> a >> b >> c;
  memset(mem, -1, sizeof(mem));
  cout << solve(a, b, c);
  return 0;
}
