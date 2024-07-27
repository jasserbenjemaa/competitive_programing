#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#define M 3
#define N 4

using namespace std;

class Node {
public:
  char c;
  unordered_map<char, Node *> childern;
  string word;
  bool isTerminal;
  Node(char c) {
    this->c = c;
    word = "";
    isTerminal = false;
  }
};

class Trie {
public:
  Node *root;
  Trie() { root = new Node('\0'); }
  void addWord(string word) {
    Node *temp = root;
    for (auto w : word) {
      if (temp->childern.count(w) == 0) {
        temp->childern[w] = new Node(w);
      }
      temp = temp->childern[w];
    }
    temp->isTerminal = true;
    temp->word = word;
  }
};

void dfs(char board[M][N], Node *node, int i, int j, bool visited[M][N],
         unordered_set<string> &output) {
  char ch = board[i][j];
  if (node->childern.count(ch) == 0) {
    return;
  }

  visited[i][j] = true;
  node = node->childern[ch];

  if (node->isTerminal) {
    output.insert(node->word);
  }
  int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
  int dy[] = {1, -1, -1, 0, 1, 1, -1, 0};

  for (int k = 0; k < 8; k++) {
    int ni = i + dx[k];
    int nj = j + dy[k];
    if (ni >= 0 && nj >= 0 && ni < M && nj < N && !visited[ni][nj]) {

      dfs(board, node, ni, nj, visited, output);
    }
  }
  visited[i][j] = false;
  return;
}

int main(int argc, char *argv[]) {
  char board[3][4] = {
      {'S', 'E', 'R', 'T'}, {'U', 'N', 'K', 'S'}, {'T', 'C', 'A', 'T'}};

  string words[] = {"SNAKE",  "FOR", "QUEZ",  "SNACK",
                    "SNACKS", "GO",  "TUNES", "CAT"};
  Trie t;
  for (auto w : words) {
    t.addWord(w);
  }
  bool visited[M][N] = {0};
  unordered_set<string> output;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {

      dfs(board, t.root, i, j, visited, output);
    }
  }

  for (auto w : output) {
    cout << w << endl;
  }

  return 0;
}
