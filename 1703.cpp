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
const int maxn = 100005;
vector<int>g[maxn];
vector<int>path;
int vis[maxn];
int dep[maxn];
int mx = 1;
int in[maxn];
int n;
bool dfs(int now) {
    path.pb(now);
    if (now == n) {
        return 1;
    }
    for (auto &i : g[now]) {
        if (!vis[i]) {
            vis[i] = 1;
            dep[i] = dep[now] + 1;
            if (dfs(i)) {
                return 1;
            }
        }
    }
    path.pop_back();
    return 0;
}
void dfs2(int now) {
    if (in[now] && dep[now] > dep[mx]) {
        mx = now;
    }
    for (auto &i : g[now]) {
        if (in[i]) {
            if (dep[i] > dep[mx]) {
                mx = i;
            }
            continue;
        }
        else if (!vis[i]) {
            vis[i] = 1;
            dfs2(i);
        }
    }
}
void go() {
    int m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
    }
    vis[1] = 1;
    dfs(1);
    vector<int>ans;
    memset(vis, 0, sizeof(vis));
    for (auto &i : path) {
        in[i] = 1;
    }
    for (auto &i : path) {
        if (mx == i) {
            ans.pb(i);
        }
        dfs2(i);
    }
    cout << ans.size() << '\n';
    sort(all(ans));
    for (auto &i : ans) {
        cout << i << ' ';
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
        go();
    }
}