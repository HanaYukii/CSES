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
int in[200005];
vector<int>g[200005];
void solve() {
    int n, m;
    cin >> n >> m;
    ll dp[n + 5] = {};
    dp[1] = 1;
    f(m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        in[y]++;
    }
    queue<int>q;
    f1(n) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        auto now = q.front();
        q.pop();
        for (auto &i : g[now]) {
            dp[i] += dp[now];
            dp[i] %= mod;
            in[i]--;
            if (!in[i]) {
                q.push(i);
            }
        }
    }
    cout << dp[n] << '\n';
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