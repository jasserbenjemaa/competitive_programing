#include <bits/stdc++.h>
#include <utility>
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

bool isWin(string s) {
  // Row check
  bool row = (s[0] != '.' && s[0] == s[1] && s[1] == s[2]) ||
             (s[3] != '.' && s[3] == s[4] && s[4] == s[5]) ||
             (s[6] != '.' && s[6] == s[7] && s[7] == s[8]);

  // Column check
  bool column = (s[0] != '.' && s[0] == s[3] && s[3] == s[6]) ||
                (s[1] != '.' && s[1] == s[4] && s[4] == s[7]) ||
                (s[2] != '.' && s[2] == s[5] && s[5] == s[8]);

  // Diagonal check
  bool diagonal = (s[0] != '.' && s[0] == s[4] && s[4] == s[8]) ||
                  (s[2] != '.' && s[2] == s[4] && s[4] == s[6]);

  // Final win check
  return row || column || diagonal;
}

int main() {
  PLAY();
  int t;
  cin >> t;
  while (t--) {

    string board = "";
    for (int i = 0; i < 3; i++) {
      string row;
      cin >> row;
      board += row;
    }
    string starting = ".........";
    queue<pair<string, bool>> que;
    que.push({starting, 1});

    string ans = "no";
    while (que.size()) {
      string curr_board = que.front().first;
      bool curr_player = que.front().second;
      que.pop();
      if (board == curr_board) {
        ans = "yes";
        break;
      }
      if (isWin(curr_board))
        continue;
      for (int i = 0; i < 9; i++) {
        if (curr_board[i] == '.') {
          curr_board[i] = (curr_player ? 'X' : 'O');
          if (curr_board[i] == board[i]) {
            que.push({curr_board, !curr_player});
          }
          curr_board[i] = '.';
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
