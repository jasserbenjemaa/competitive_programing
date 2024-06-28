#include<bits/stdc++.h>
#include <chrono>
using namespace std;

int howManybits(int n){
  int k=0;
  if(n<2) return 0;
  while(n>>k){
    k++;
  }
  return (1<<(k-1))-1;
}

int main (int argc, char *argv[]) {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);

  auto start_time = chrono::high_resolution_clock::now();
  #endif

  int t,n;
  cin >> t;
  while(t--){
    cin >>n;
    
    cout<<howManybits(n)<<endl;
  }
  
    #ifndef ONLINE_JUDGE
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Time taken by the program: " << duration.count() << " microseconds." << endl;
    #endif
  return 0;
}
