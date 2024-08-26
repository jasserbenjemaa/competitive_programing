#include <bits/stdc++.h>
#include <csignal>
#include <vector>
using namespace std;
int n, m, w, q;
struct Point {
  int x, y;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  cin >> n >> m >> w >> q;
  vector<Point> arr(w);
  string f[] = {"Grapes", "Carrots", "Kiwis"};
  for (int i = 0; i < w; i++) {
    cin >> arr[i].y >> arr[i].x;
  }
  for (int i = 0; i < q; i++) {
    bool isWaste = false;
    Point p;
    cin >> p.y >> p.x;
    // Calculate the position in the flattened grid
    int pos = (p.y - 1) * m + p.x;
    for (int j = 0; j < w; j++) {
      if (arr[j].y < p.y || (arr[j].x < p.x && arr[j].y == p.y)) {
        pos--;
      }
      if (arr[j].y == p.y && arr[j].x == p.x) {
        isWaste = true;
        break;
      }
    }
    if (isWaste)
      cout << "Waste" << endl;
    else
      cout << f[pos % 3] << endl;
  }

  return 0;
}
