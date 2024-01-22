#include <bits/stdc++.h>
#include <chrono>
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
    auto start_time = chrono::high_resolution_clock::now();
  #endif
  
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  #ifndef ONLINE_JUDGE
  auto end_time = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time) ;
  cout << "Time:"<<duration.count()<<endl;
  #endif
  return 0;
}
