#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define mod 1000000007

#define N 100
char M[N][N];
int visited[N][N];
int m;
int n;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int i,int j){
  if (visited[i][j]) return;
  visited[i][j]=1;
  for(int k=0;k<4;k++){
    int nj=j+dx[k];
    int ni=i+dy[k];
    if(nj>=0 && nj<m && ni>=0 && ni<m && (M[ni][nj]=='x' || M[ni][nj]=='@') && !visited[ni][nj]){
      dfs(ni,nj);
    }
  }
}

void c_p_c() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
}

int32_t main() {
    c_p_c();
    cin>>n;
    int case_n=1;
    while(n--){
      int ships_numbers=0;
      cin>>m;
      memset(visited,0,sizeof(visited));
      for (int i=0;i<m;i++){
        for(int j=0;j<m;j++){
          cin>>M[i][j];
        }
      }
      for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
          if(M[i][j]=='x' && !visited[i][j]){
            dfs(i,j);
            ships_numbers++;
          }
        }
      }
      printf("Case %d: %d\n",case_n++,ships_numbers);
    }
    return 0;
}
