#include <bits/stdc++.h>
#define N 20
using namespace std;
int n, k;

void swapRow(int m[N][2], int j) {
  int temp[] = {m[0][j], m[1][j]};

  m[j + 1][0] = m[j][0];
  m[j + 1][1] = m[j][1];

  m[j][0] = temp[0];
  m[j][1] = temp[1];
}

void insertionSortMat(int m[N][2], int k) {
  for (int i = 1; i < k; i++) {
    int v[] = {m[i][0], m[i][1]}, j = i - 1;
    while (j >= 0 && v[1] > m[j][1]) {
      swapRow(m, j);
      j--;
    }
    m[j + 1][1] = v[1];
    m[j + 1][0] = v[0];
  }
}

int calculatMatches(int m[N][2], int n, int k) {
  int sum = 0;
  for (int i = 0; i < k && n > 0; i++) {
    if (n - m[i][0] > 0) {
      sum += m[i][0] * m[i][1];
    } else {
      sum += n * m[i][1];
    }
    n -= m[i][0];
  }
  return sum;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  cin >> n >> k;
  int m[k][2];

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> m[i][j];
    }
  }

  insertionSortMat(m, k);
  cout << calculatMatches(m, n, k) << endl;

  return 0;
}
