#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define mod 1000000007


int sum(int n ){
  return n*(n+1)/2;
}
int partial_sum(int k,int n){
  return ((n-k+1)*(k+n))/2;
}

int binairy_search_min_spliter(int n,int k){
  int st=1,ed=k;
  while(st<ed){
    int mid=(st+ed)/2;
    int p_sum=partial_sum(mid,k);
    if(n==p_sum){
      return k-mid+1;
    }
    if(n<p_sum){
      st=mid+1;
    }
    else{
      ed=mid;
    }
  }
  return k-st+2;
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
  int n,k;
  cin>>n>>k;
  if (n==1) {
    cout<<0<<endl;
    return 0;
  }
  if(n<=k){
    cout<<1<<endl;
    return 0;
  }
  n--,k--;
  if(sum(k)<n){
    cout<<-1<<endl;
    return 0;
  }
  cout<<binairy_search_min_spliter(n,k);
  return 0;
}
