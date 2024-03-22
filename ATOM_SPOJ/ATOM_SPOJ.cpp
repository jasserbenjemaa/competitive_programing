#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#define int long long int

using namespace std;

int32_t main () {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
  #endif
  
  int r,n,m,k,t;
  scanf("%lld", &r);
  while (r--) {
    scanf("%lld %lld %lld", &n, &k, &m);
    t=log10(m/n)/log10(k);
    if(n>m){
      printf("0\n");
      continue;
    }
    printf("%lld\n", t);

  }

  return 0;
}

