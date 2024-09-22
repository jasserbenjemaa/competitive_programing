#include <bits/stdc++.h>
using namespace std;

#define N 10000 + 9

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

int main() {
  PLAY();
  long long int n, count = 1;
  bool ok = false;
  cin >> n;
  int k[n];
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    if (k[i] == 1) {
      ok = true;
    }
  }
  if (!ok) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (k[i] == 1) {
      for (int j = i + 1; j < n; j++) {
        if (k[j] == 1) {
          count = count * (j - i);
          break;
        }
      }
    }
  }
  cout << count;
}
