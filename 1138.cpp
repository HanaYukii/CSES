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
int v[200005];
int in[200005];
int out[200005];
int dfn;
ll b[200005];
void dfs(int now, int pre) {
    in[now] = ++dfn;
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        dfs(i, now);   
    }
    out[now] = dfn + 1;
}
void update(int x, int d) {
    while (x <= dfn) {
        b[x] += d;
        x += x & (-x);
    }
}
ll query(int x) {
    ll ret = 0;
    while (x) {
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
void solve() {
    int n, q;
    cin >> n >> q;
    f1 (n) {
        cin >> v[i];
    }
    fr(i,2,n+1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    f1(n) {
        update(in[i], v[i]);
        update(out[i], -v[i]);
    }
    while(q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int s, x;
            cin >> s >> x;
            update(in[s], x - v[s]);
            update(out[s], v[s] - x);
            v[s] = x;
        }
        else {
            int x;
            cin >> x;
            cout << query(in[x])<< '\n';
        }
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