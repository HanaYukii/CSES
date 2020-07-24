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
int sz[200005];
void dfs(int now) {
    sz[now] = 1;
    for (auto &i : g[now]) {
        dfs(i);
        sz[now] += sz[i];
    }
}
void solve() {
    int n;
    cin >> n;
    f(n - 1) {
        int x;
        cin >> x;
        g[x].pb(i + 2);
    }
    dfs(1);
    f1(n) {
        cout << sz[i] - 1 << ' ';
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