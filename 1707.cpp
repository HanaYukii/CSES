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
const int maxn = 2e5+5;
vector<pair<int,int>>e;
vector<int>g[2505];
void solve() {
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(e.size());
        g[y].pb(e.size());
        e.pb({x,y});
    }
    int mi = 1e9;
    f(e.size()) {
        int d[n+1];
        memset(d, -1, sizeof(d));
        d[e[i].F] = 0;
        queue<int>q;
        q.push(e[i].F);
        while (q.size()) {
            int now = q.front();
            q.pop();
            for (auto &j : g[now]) {
                if (j == i)continue;
                int to;
                if (e[j].F == now) {
                    to = e[j].S;
                }
                else {
                    to = e[j].F;
                }
                if (d[to] == -1) {
                    d[to] = d[now] + 1;
                    q.push(to);
                }
            }
        }
        if (~d[e[i].S]) {
            mi = min(mi, d[e[i].S] + 1);
        }  
    }
    if (mi == 1e9) {
        mi = -1;
    }
    cout << mi << '\n';
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