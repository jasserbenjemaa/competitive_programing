#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int findFirstSetBit(int n){
  int k=0;
  while(!((n>>k)&1)){
    k++;
  }
  return k;
}


void solve(){
  int n,k,ans;
  cin>>n;
  k=findFirstSetBit(n);
  //cout << k<<endl;
  ans=(1<<k);
  while(!(ans^n && ans&n)){
    ans++;
  }

  cout << ans<<endl;
  
}

int main (int argc, char *argv[]) {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    auto start = chrono::high_resolution_clock::now();
  #endif
    int t;
    cin >>t;
    while (t--) {
    solve(); 
    }

  #ifndef ONLINE_JUDGE
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);
    cout <<"duration:" <<duration.count() << endl;
  
  #endif 
} 
