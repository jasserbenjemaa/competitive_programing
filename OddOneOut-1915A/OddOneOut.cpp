#include <iostream>
#include <ostream>

using namespace std;

int findOddOneOut(int a,int b,int c){
  return a^b^c;
}

int main (int argc, char *argv[]) {
  #ifndef ONLINE_JUDGE
  
  freopen("input.txt", "r", stdin);
  #endif // !ONLINE_JUDGE
  int t,a,b,c;
  cin >> t;
  for (int i=0;i<t;i++){
   cin >>a>>b>>c;
    cout<<findOddOneOut(a,b, c)<<endl;
  }
  
  return 0;
}
