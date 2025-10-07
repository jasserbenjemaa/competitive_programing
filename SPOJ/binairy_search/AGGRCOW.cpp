#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define mod 1000000007
#define inf 1e18
#define N 100000

int n,c;
int pos[N];

bool try_distance(int mid){
  int prev_cow=pos[0],count=1;
  for(int i=1;i<n;i++){
    if(pos[i]-prev_cow>=mid){
      count++;
      prev_cow=pos[i];
    }
  }
  if(count>=c)return true;
  return false;
  
}

int pos_binairy_search(){
  int st=0,en=1e9+7,mid;
  while(st<en-1){
    mid=(st+en)/2;
    if(try_distance(mid)){
      st=mid;
    }
    else{
      en=mid-1;
    }
  }
  if(try_distance(en))return en;
  else return st;
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
    int t;
    cin>>t;
    while (t--) {
      cin>>n>>c;
      for(int i=0;i<n;i++){
        cin>>pos[i];
      }
      sort(pos,pos+n);
      cout<<pos_binairy_search()<<endl;
    }
    return 0;
}
