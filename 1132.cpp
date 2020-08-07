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
void dfs(int now, int pre, vector<int>& v) {
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        v[i] = v[now] + 1;
        dfs(i, now, v);
    }
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
    vector<int>v(n + 1), v2(n + 1), v3(n + 1);
    v[1] = 0;
    dfs(1, 0, v);
    int mx = 1;
    f1 (n) {
        if (v[i] > v[mx]) {
            mx = i;
        }
    }
    v2[mx] = 0;
    dfs(mx, 0, v2);
    mx = 1;
    f1 (n) {
        if (v2[i] > v2[mx]) {
            mx = i;
        }
    }
    v3[mx] = 0;
    dfs(mx, 0, v3);
    f1(n) {
        cout << max(v2[i], v3[i]) <<' ';
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