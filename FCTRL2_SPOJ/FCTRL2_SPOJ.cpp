#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define int long long int
using namespace std;

void multiply(vector<int> &vect,int m,int &size){
  int carry=0,d;
  for(int i=0;i<size;i++){
    d=vect[i]*m+carry; 
    vect[i]=d%10;
    carry=d/10;
  }
  while (carry) {
    vect[size]=carry%10;
    carry/=10;
    size++;
  }
} 
int32_t main () {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
  #endif
  int t,n;
  cin>>t;
  while(t--){
  int size=1;
  vector<int> vect(1000,0);
    vect[0]=1;
    cin>>n;
    for(int i=2;i<=n;i++){
      multiply(vect,i,size);
    }
    for(int i=size-1;i>=0;i--){
      cout<<vect[i];
    }
    cout<<endl;
  }
  return 0;
}
