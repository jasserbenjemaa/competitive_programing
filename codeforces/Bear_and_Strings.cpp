#include <bits/stdc++.h>
#include <vector>
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
  string s;
  cin >> s;
  int n = s.size(), sum = 0;
  vector<int> posBears;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r') {
      posBears.push_back(i);
    }
  }
  for (int i = 0; i < posBears.size(); i++) {
    int posPreviosBear = 0, lettersAfter = n - (posBears[i] + 3);
    if (i)
      posPreviosBear = posBears[i - 1] + 1;
    posPreviosBear = posBears[i] - posPreviosBear + 1;
    sum += posPreviosBear * lettersAfter;
  }
  cout << sum;

  return 0;
}
