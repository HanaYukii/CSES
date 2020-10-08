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
int d[maxn];
vector<int>v[maxn], g[maxn];
int in[maxn];
int fi(int x) {
    return d[x] < 0 ? x : d[x] = fi(d[x]);
}
int topo(int x) {
    int cnt = 0;
    queue<int>q;
    for (auto &i : v[x]) {
        if (!in[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        auto now = q.front();
        q.pop();
        cnt++;
        for (auto &i : g[now]) {
            in[i]--;
            if (!in[i]) {
                q.push(i);
            }
        }
    }
    if (cnt == v[x].size()) {
        return v[x].size() - 1;
    }
    else {
        return v[x].size();
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    f (m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        in[y]++;
        x = fi(x);
        y = fi(y);
        if (x != y) {
            d[x] += d[y];
            d[y] = x;
        }
    }
    f1 (n) {
        v[fi(i)].pb(i);
    }
    int ans = 0;
    f1 (n) {
        if (v[i].size()) {
            ans += topo(i);
        }
    }
    cout << ans << '\n';
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