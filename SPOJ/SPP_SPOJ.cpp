
#include <iostream>
#include <cstring>
#include <chrono>
#define ll long long int
using namespace std;

const int MAX_SIZE = 17;
ll mod;

struct Mat {
    int n;
    ll m[MAX_SIZE][MAX_SIZE];

    Mat(int n) : n(n) {
        memset(m, 0, sizeof(m));
    }

    void identity() {
        for (int i = 0; i < n; ++i) {
            m[i][i] = 1;
        }
    }

    Mat operator*(Mat a) {
        Mat ans(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ans.m[i][j] += (m[i][k] * a.m[k][j]) % mod;
                    ans.m[i][j] %= mod;
                }
            }
        }
        return ans;
    }
};

ll spp(int k, ll* c, ll* b, ll n) {
    ll res = 0;
    Mat T(k + 1), ans(k + 1);
    if (n <= k) {
      for(int i=1;i<=n;i++){
        res+=b[i];
        res%=mod;
    }
    return res;
    }
    ans.identity();
    T.m[0][0] = 1;
    T.m[1][0] = 0;
    for (int i = 1; i < k + 1; ++i) {
        T.m[0][i] = c[i - 1];
        T.m[1][i] = c[i - 1];
        T.m[i + 1][i] = 1;
    }
    n -= k;
    while (n) {
        if (n & 1) ans = ans * T;
        T = T * T;
        n /= 2;
    }
    for (int i = 0; i < k + 1; ++i) {
        res += ans.m[0][i] * b[i];
        res %= mod;
    }
    return res;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        ll n,m,result;
        cin >> k;
        ll c[k], b[k + 1];
        b[0] = 0;
        for (int i = k; i >= 1; --i) {
            cin >> b[i];
            b[0] += b[i];
        }
        for (int i = 0; i < k; ++i) {
            cin >> c[i];
        }
        cin >>m>> n >> mod;
        result=(spp(k, c, b, n)%mod-spp(k, c, b, m - 1)%mod+mod)%mod; 
      cout <<result<< endl;
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

