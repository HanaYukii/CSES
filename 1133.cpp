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
int sz[200005];
ll ans[200005];
int n;
void dfs(int now, int pre, int d) {
    ans[1] += d;
    sz[now] = 1;
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        dfs(i, now, d + 1);
        sz[now] += sz[i];
    }
}
void dfs2(int now, int pre) {
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        ans[i] = ans[now] + n - sz[i] * 2;
        dfs2(i, now);
    }
}
void solve() {
    cin >> n;
    f(n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0, 0);
    dfs2(1, 0);
    f1 (n) {
        cout << ans[i] <<' ';
    }
    cout << '\n';
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