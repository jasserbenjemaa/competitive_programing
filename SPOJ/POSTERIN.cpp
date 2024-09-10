#include <bits/stdc++.h>
#include <stack>
using namespace std;

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
  int n;
  cin >> n;
  int k[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x >> k[i];
  }
  stack<int> s;
  int p = 0;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && s.top() > k[i]) {
      s.pop();
    }
    if (s.empty()) {
      s.push(k[i]);
      p++;
    }
    if (s.top() < k[i]) {
      s.push(k[i]);
      p++;
    }
  }
  cout << p;

  return 0;
}
