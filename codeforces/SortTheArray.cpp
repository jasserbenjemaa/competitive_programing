#include <bits/stdc++.h>
#include <utility>
using namespace std;
bool isSorted(int k[], int n) {
  int i = 0;
  while (k[i] < k[i + 1] && i < n - 1)
    i++;
  return i == n - 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int n, i, j;
  bool notSorted = true;
  cin >> n;
  int k[n];
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      swap(k[j], k[i]);
      if (isSorted(k, n)) {
        notSorted = false;
        break;
      }
      swap(k[j], k[i]);
    }
    if (!notSorted)
      break;
  }
  if (notSorted)
    cout << "no";
  else
    cout << "yes" << '\n' << i + 1 << " " << j + 1;

  return 0;
}
