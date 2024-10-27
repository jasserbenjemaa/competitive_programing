#include <bits/stdc++.h>
using namespace std;

void solve(){
  int k,j,x,ans;
  cin >> k >>j;
  x=k&j;
  ans=(k^x)+(j^x);
  cout << ans<<endl;
}

int main (int argc, char *argv[]) {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
  #endif
  
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
 
  return 0;
}
