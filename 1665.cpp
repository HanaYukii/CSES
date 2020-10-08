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
int v[105];
int n;
int x;
ll dp[105][55][5005];
int vis[105][55][5005];
ll DP(int pos, int have, int p) {
    if (vis[pos][have][p]) {
        return dp[pos][have][p];
    }
    if (n - pos + 1 < have || p > x) {
        return dp[pos][have][p] = 0;
    }
    if (pos == n + 1) {
        return 1;
    }
    int nxt = p + have * (v[pos] - v[pos - 1]);
    ll ans = 0;
    ans += DP(pos + 1, have, nxt);
    ans += DP(pos + 1, have + 1, nxt);
    ans += DP(pos + 1, have, nxt) * have;
    if (have) {
        ans += DP(pos + 1, have - 1, nxt) * have;
    }
    ans %= mod;
    vis[pos][have][p] = 1;
    return dp[pos][have][p] = ans;
}
void solve() {
    cin >> n >> x;
    f1(n) {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    //memset(dp, -1, sizeof(dp));
    cout << DP(1, 0, 0) << '\n';
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