#include <bits/stdc++.h>
using namespace std;
int maxSection(int n, int k[]) {
  int max = 0;
  for (int i = 0; i < n; i++) {
    int val = 0, j = i;
    while (k[j] >= k[j + 1] && j < n - 1)
      val++, j++;

    j = i;

    while (k[j] >= k[j - 1] && j > 0)
      val++, j--;
    if (val > max)
      max = val;
  }

  return max;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  int k[n];
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  cout << maxSection(n, k) + 1 << endl;
  return 0;
}
