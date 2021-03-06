#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 1000005;
struct mat {
    ll a[6][6];
    mat() {
        memset(a, 0, sizeof(a));
    }
    mat operator * ( const mat &b ) const {
        mat ret;
        for( int i = 0; i < 6; ++i )
            for( int j = 0; j < 6; ++j )
                for( int k = 0; k < 6; ++k )
                    ret.a[i][j] = ( ret.a[i][j] + a[i][k] * b.a[k][j] ) % mod;
        return ret;
    }
};
void solve() {
    ll n;
    mat ans, now;
    cin >> n;
    f(5) {
        now.a[i][i + 1] = 1;
    }
    f(6) {
        now.a[5][i] = 1;
    }
    ans.a[5][0] = 1;
    while (n) {
        if (n & 1) {
            ans = now * ans;
        }
        now = now * now;
        n >>= 1;
    }
    cout << ans.a[5][0] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        solve();
    }
}