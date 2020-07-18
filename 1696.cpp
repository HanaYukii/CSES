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
const int maxn = 2000005;
int v[505];
vector<int>g[505];
int ma[505];
int dfs(int now) {
    for (auto &i : g[now]) {
        if (!ma[i]) {
            ma[i] = now;
            return 1;
        }
        else if (v[i]) {
            continue;
        }
        else {
            v[i] = 1;
            if (dfs(ma[i])) {
                ma[i] = now;
                return 1;
            }
        }
    }
    return 0;
}
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    f (k) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
    }
    int ans = 0;
    f1(n) {
        memset(v, 0, sizeof(v));
        if (dfs(i)) {
            ans++;
        }
    }
    cout << ans << '\n';
    f1(m) {
        if (ma[i]) {
            cout << ma[i] << ' ' << i << '\n';
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