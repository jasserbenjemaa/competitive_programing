#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define N 50000
int n, k;
vector<int> l(N);

int findFirstshort(int x) {
  int s = 0, e = n - 1;
  int ans = -1;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (x > l[mid]) {
      s = mid + 1;
      ans = l[mid];
    } else {
      e = mid - 1;
    }
  }
  return ans;
}

int findFirstTall(int x) {
  int s = 0, e = n - 1;
  int ans = -1;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (x < l[mid]) {
      ans = l[mid];
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int j;
    cin >> j;
    int s = findFirstshort(j);
    int t = findFirstTall(j);
    if (s == -1) {
      cout << "X ";
    } else {
      cout << s << " ";
    }
    if (t == -1) {
      cout << "X" << endl;
    } else {
      cout << t << endl;
    }
  }
  return 0;
}

