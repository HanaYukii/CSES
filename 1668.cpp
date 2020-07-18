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
const int maxn = 1000005;
vector<int>g[200005];
int c[200005];
void dfs(int now, int cc) {
    for (auto &i : g[now]) {
        if (c[i] == c[now]) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        if (!c[i]) {
            c[i] = ((c[now] - 1) ^ 1) + 1;
            dfs(i, c[i]);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    f1(n) {
        if (!c[i]) {
            c[i] = 1;
            dfs(i,1);
        }
    }
    f1(n) {
        cout << c[i] <<' ';
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