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
int pa[200005][18];
int dep[200005];
void dfs(int now, int pre) {
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        dep[i] = dep[now] + 1;
        pa[i][0] = now;
        dfs(i, now);   
    }
}
int lca(int x, int y) {
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    int d = dep[x] - dep[y];
    f(18) {
        if (d & (1<<i)) {
            x = pa[x][i];
        }
    }
    if (x == y) {
        return y;
    }
    for (int i = 17 ; i >= 0 ; i--) {
        if (pa[x][i] != pa[y][i]) {
            x = pa[x][i];
            y = pa[y][i];
        }
    }
    return pa[x][0];
}
void solve() {
    int n, q;
    cin >> n >> q;
    fr(i,2,n+1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    f1(17) {
        fr(j,1,n+1) {
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << dep[x] + dep[y] - 2 * dep[lca(x, y)] << '\n';
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