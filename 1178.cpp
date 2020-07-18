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
const int maxn = 200005;
vector<int>g[100005];
int pa[100005];
int v[100005];
void dfs(int now) {
    v[now] = 1;
    for (auto &i : g[now]) {
        if (v[i] == 2) {
            continue;
        }
        else if (v[i] == 1) {
            vector<int>ans;
            ans.pb(now);
            while (ans.back() != i) {
                ans.pb(pa[ans.back()]);
            }
            ans.pb(now);
            reverse(all(ans));
            cout << ans.size() << '\n';
            for (auto &i : ans) {
                cout << i << ' ';
            }
            cout << '\n';
            exit(0);
        }
        else {
            pa[i] = now;
            dfs(i);
        }
    }
    v[now] = 2;
}
void solve() {
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
    }
    for(int i = n ; i >= 1 ; i--) {
        if (!v[i]) {
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE\n";
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