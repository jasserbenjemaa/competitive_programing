#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
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
struct Point {
  int x, y, r;
};
int n;
vector<Point> pts(1000);
double dist(int x1, int y1, int x2, int y2) {
  return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int check(int x1, int y1) {
  int j = 0;
  while (dist(x1, y1, pts[j].x, pts[j].y) > pts[j].r * pts[j].r && j < n)
    j++;
  return j == n;
}

int main() {
  PLAY();
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int count = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y >> pts[i].r;
  }
  for (int i = min(y1, y2); i <= max(y1, y2); i++) {
    count += check(x1, i);
    count += check(x2, i);
  }
  for (int i = min(x1, x2) + 1; i <= max(x1, x2) - 1; i++) {
    count += check(i, y1);
    count += check(i, y2);
  }
  cout << count;

  return 0;
}
