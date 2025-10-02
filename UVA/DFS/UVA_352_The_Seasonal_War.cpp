#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define N 30
char M[N][N];
int visited[N][N];
int n;
int dx[] = {0, 0, 1, -1,1,1,-1,-1};
int dy[] = {1, -1, 0, 0,1,-1,-1,1};

void dfs(int i, int j) {
  if (visited[i][j]) return;
  visited[i][j] = 1;
  for(int k=0;k<8;k++){
    int ni=i+dy[k];
    int nj=j+dx[k];
    if(!visited[ni][nj] && ni<n && ni>=0 && nj<n && nj>=0 && M[i][j]=='1'){
      dfs(ni,nj);
    }
  }
  
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  int image_number=1;
  while (cin>>n){
  int war_number=0;
  for (int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>M[i][j];
    }
  }
  memset(visited,0,sizeof(visited));

  for (int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(M[i][j]=='1' && !visited[i][j]){
        dfs(i,j);
        war_number++;
      }
    }
  }
  printf("Image number %d contains %d war eagles.\n",image_number,war_number);
  image_number++;
  }
  return 0;
}
