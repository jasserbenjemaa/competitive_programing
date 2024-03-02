#include <iostream>
#include <cstring>
#include <chrono>
#define ll  long  long
using namespace std;
const  ll int mod = 1e9;
struct Mat {
    int n;
    ll int m[10][10];

    Mat(int n) : n(n) {
        memset(m, 0, sizeof(m));
    }

    void identity() {
        for(int i = 0; i < n; ++i) {
            m[i][i] = 1;
        }
    }

    Mat operator*(Mat a) {
        Mat ans(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    ans.m[i][j] += (m[i][k] * a.m[k][j])%mod;
                    ans.m[i][j]%=mod;
                }
            }
        }
        return ans;
    }
};



ll int seq(ll int k, ll int* c, ll int* b, ll int n) {
    ll int res = 0;
    Mat T(k), ans(k);
    if(n <= k) {
        return b[n - 1];
    }
    ans.identity();
    for(int i = 0; i < k; ++i) {
        T.m[0][i] = c[i];
        if(i < k - 1) {
            T.m[i + 1][i] = 1;
        }
    }
    n -= k;
    while(n) {
        if(n & 1) ans = ans * T;
        T = T * T;
        n /= 2;
    }
    for(int i = 0; i < k; ++i) {
        res +=ans.m[0][i] * b[i];
        res%=mod;
    }
    return res;
}

void solve() {
    long long int t, k, n;

    cin >> t;
   while(t--) {
        cin >> k; 
        long long int  c[k], b[k];
        for(int i = k-1; i >= 0 ; --i) {
            cin >> b[i];
        }
        for(int i = 0; i < k; ++i) {
            cin >> c[i];
        }
        cin >> n;
        cout << seq(k, c, b, n) << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    auto start_time = chrono::high_resolution_clock::now();
#endif
    solve();
#ifndef ONLINE_JUDGE
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << "\nTime: " << duration.count() << " milliseconds" << endl;
#endif
    return 0;
}

