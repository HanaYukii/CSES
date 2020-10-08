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
const int maxn = 1e5+5;
vector<pair<int,int>>g[maxn][2];
vector<int>g2[maxn];
int low[maxn];
int dfn[maxn];
int pa[maxn];
int vis[maxn];
int c[maxn];
int n;
int st;
void tarjan(int x) {
    dfn[x] = ++st;
    low[x] = dfn[x];
    vis[x] = 1;
    for (auto &i : g2[x]) {
        if (!vis[i]) {
            pa[i] = x;
            tarjan(i);
            low[x] = min(low[x], low[i]);
            if (low[i] >= dfn[x]) {
                c[x] = 1;
            }
        }
        else if (i != pa[x]) {
            low[x] = min(low[x], dfn[i]);
        }
    }
}
vector<ll>dij(int st, int tp) {
    vector<ll>ret(n + 5, (ll)1e18);
    ret[st] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0, st});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (ret[now.S] != now.F) {
            continue;
        }
        for (auto &i:g[now.S][tp]) {
            if (ret[now.S] + i.S < ret[i.F]) {
                ret[i.F] = ret[now.S] + i.S;
                pq.push({ret[i.F], i.F});
            }
        }
    }
    return ret;
}
void solve() {
    int m;
    cin >> n >> m;
    f (m) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][0].pb({y, z});
        g[y][1].pb({x, z});
    }
    vector<ll>v1 = dij(1, 0);
    vector<ll>v2 = dij(n, 1);
    f1(n) {
        for (auto &j : g[i][0]) {
            if (v1[n] == v1[i] + v2[j.F] + j.S) {
                g2[i].pb(j.F);
                g2[j.F].pb(i);
            }
        }
    }
    tarjan(1);
    c[1] = c[n] = 1;
    vector<int>v;
    f1(n) {
        if (c[i]) {
            v.pb(i);
        }
    }
    cout << v.size() << '\n';
    for (auto &i : v) {
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
        solve();
    }
}