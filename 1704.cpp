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
vector<int>leaf;
vector<int>g[maxn];
void dfs(int now, int pre) {
    if (g[now].size() == 1) {
        leaf.pb(now);
    }
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        dfs(i, now);
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
    dfs(1,0);
    int x = (leaf.size() + 1) / 2;
    cout << leaf.size() / 2 + leaf.size() % 2 << '\n';
    f(leaf.size()/2) {
        cout << leaf[i] <<' '<<leaf[i + x] << '\n';
    }
    if (leaf.size() & 1) {
        cout << leaf[leaf.size()/2] <<' '<<leaf[0] << '\n';
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