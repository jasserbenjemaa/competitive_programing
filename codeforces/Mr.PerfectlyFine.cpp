#include <bits/stdc++.h>
#include <chrono>
#include <string>
using namespace std;
long long mod=10000000;

long solve(){
  long arr[3]={mod,mod,mod};
  string bits;
  int k,n;
  cin >> k;
  for (int i=0;i<k;i++){
    cin >>n >>bits;
    if(arr[0]>n && arr[1]!=0 && bits=="10"){
      arr[0]=n;
        }
    else if(arr[1]>n && arr[1]!=0 && bits=="01"){
          arr[1]=n;
        }
    else if(arr[2]>n && bits=="11"){
     arr[2]=n ;
        }
    }
  long res = arr[0]+arr[1]>arr[2] ? arr[2]:arr[0]+arr[1];
  return res >= mod ? -1 : res;
  
}
int main (int argc, char *argv[]) {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    auto start_time = chrono::high_resolution_clock::now();
  #endif
  
  int t;
  cin >> t;
  while (t--) {
    cout<<solve()<<endl;
  }

  #ifndef ONLINE_JUDGE
  auto end_time = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time) ;
  cout << "Time:"<<duration.count()<<"milliseconds"<<endl;
  #endif
  return 0;
}
