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
const int maxn = 2000005;
int dp[1<<20][20];
vector<int>g[20];
int DP(int mask, int pos) {
    //cout << mask << ' ' << pos << endl;
    if (~dp[mask][pos]) {
        return dp[mask][pos];
    }
    if (__builtin_popcount(mask) == 1) {
        if (mask == 1)
            return dp[mask][pos] = 1;
        else
            return dp[mask][pos] = 0;
    }
    ll ans = 0;
    for (auto &i : g[pos]) {
        if (!(mask&(1<<i))) continue;
        ans += DP(mask ^ (1<<pos),i);
        ans %= mod;
    }
    return dp[mask][pos]  = ans;
}
void solve() {
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        if (x == y)continue;
        x--, y--;
        g[y].pb(x);
    }
    memset(dp, -1, sizeof(dp));
    cout << DP((1<<n)-1,n-1) << '\n';
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