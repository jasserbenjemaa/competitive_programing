#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

char findChar(){
    for(int i=0;i<3;i++){
    char mat[3];

    cin >> mat[0]>>mat[1]>>mat[2];
    int res = (mat[0]+mat[1]+mat[2])-3*63;
    if(res<9){
      return 'A'+7-res;
    }
  }
}

int main (int argc, char *argv[]) {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    auto start_time = chrono::high_resolution_clock::now();
  #endif

  int t;
  cin >> t;

  while (t--) {
       cout<<findChar()<<endl;
    }

  #ifndef ONLINE_JUDGE
  auto end_time = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

  cout << "Time:"<<duration.count()<<endl;
  
  #endif 
     return 0;
}
