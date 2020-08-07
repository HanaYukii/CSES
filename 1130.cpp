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
vector<int>g[200005];
int dp[200005][2];
void dfs(int now,int pre) {
    int sm = 0;
    int mi = 1;
    for (auto &i : g[now]) {
        if (i != pre) {
            dfs(i, now);
        
            sm += dp[i][0];
            if (dp[i][0] == dp[i][1]) {
                mi = 0;
            }
        }
    }
    dp[now][0] = sm - mi + 1;
    dp[now][1] = sm;
}
void solve() {
    int n;
    cin >> n;
    f(n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';;
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