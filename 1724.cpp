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
int n;
struct mat {
    ll a[100][100];
    mat() {
        memset(a, 0x1f, sizeof(a));
    }
    mat operator * ( const mat &b ) const {
        mat ret;
        for( int i = 0; i < n; ++i )
            for( int j = 0; j < n; ++j )
                for( int k = 0; k < n; ++k )
                    ret.a[i][j] = min(ret.a[i][j], a[i][k] + b.a[k][j]);
        return ret;
    }
};
void solve() {
    int m, k;
    cin >> n >> m >> k;
    mat now;
    f(m) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        now.a[x][y] = min(now.a[x][y], 1LL * z);
    }
    mat ans = now;
    k--;
    while (k) {
        if (k & 1) {
            ans = ans * now;
        }
        now = now * now;
        k >>= 1;
    }
    if (ans.a[0][n-1] <= 1e18) {
        cout << ans.a[0][n - 1] << '\n';
    }
    else {
        cout << -1 << '\n';
    }
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