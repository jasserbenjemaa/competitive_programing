#include <bits/stdc++.h>
#include <cstdint>
#define int long long int
using namespace std;

const int sz = 2;
const int mod =1e9 +7;
struct Mat {
  int m[sz][sz];
  Mat(){
    memset(m, 0, sizeof(m));
  }
  void identity(){
    for (int i=0 ;i<sz;i++) {
      m[i][i]=1;
    }
  }
  Mat operator*(Mat a){
    Mat result;
    for(int i=0;i<sz;i++){
      for(int j=0;j<sz;j++){
        for(int k=0;k<sz;k++){
          result.m[i][j]+=m[i][k]*a.m[k][j];
          result.m[i][j] %= mod;
        }
      }
    }
    return result;
  }
  
};
int fib(int n){
  Mat res,T;
  res.identity();
  T.m[0][0]=T.m[0][1]=T.m[1][0]=1;
  if (n<=2) return 1;
  n-=2;
  while (n) {
    if(n&1) res=res * T;
    T=T*T;
    n/=2;
  }
  return ( res.m[0][0]+res.m[0][1])%mod;

}
int32_t main () {
  int n;
  cin >>n;
    cout<<fib(n);
  

	return 0;
} 
