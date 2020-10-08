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
const int maxn = 1e6+5;
int pa[maxn][20];
int gp(int x, int p, int r) {
    int pos = x;
    for (int i = 0 ; i <= 19 ; i++) {
        if (p & 1) {
            pos = pa[pos][i];
        }
        p >>= 1;
        if (pos > r) {
            break;
        }
    }
    return pos;
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>>pool;
    f(n) {
        int x, y;
        cin >> x >> y;
        pool.pb({x,y});
    }
    sort(all(pool));
    int mi = 1e6+1;
    for (int i = 1000001 ; i >= 1 ; i--) {
        while (pool.size() && pool.back().F >= i) {
            mi = min(mi, pool.back().S);
            pool.pop_back();
        }
        pa[i][0] = mi;
    }
    f1(19) {
        fr(j,1,1000002) {
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (int i = 19 ; i >= 0 ; i--) {
            ans <<= 1;
            if (pa[x][i] <= y) {
                x = pa[x][i];
                ans++;
            }
        }
        cout << ans << '\n';
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