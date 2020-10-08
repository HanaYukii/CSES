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
const int maxn = 200005;
int v[20];
int n,u;
ll dp[1048576];
ll DP(int x) {
    if (~dp[x]) {
        return dp[x];
    }
    if (!x) {
        return dp[x] = 0;
    }
    ll mi = 1e18;
    for (int i = 0 ; i < n ; i++) {
        if (x & (1<<i)) {
            ll y = DP(x^(1<<i));
            if ((y + v[i] - 1)/u != (y - 1)/u) {
                y = ((y - 1)/u + 1) * u;
            }
            y += v[i];
            mi = min(mi, y);
        }
    }
    return dp[x] = mi;
}
void solve() {
    memset(dp, -1 ,sizeof(dp));
    cin >> n >> u;
    f(n) {
        cin >> v[i];
    }    
    cout << (DP((1<<n)-1) - 1) / u + 1<< '\n';
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