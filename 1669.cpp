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
int fr[200005];
void dfs(int now, int pre) {
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        if (fr[i]) {
            vector<int>ans;
            ans.pb(now);
            int nxt = fr[now];
            while(1) {
                ans.pb(nxt);
                if (nxt == i) {
                    break;
                }
                nxt = fr[nxt];
            }
            ans.pb(now);
            cout << ans.size() << '\n';
            for (auto &i : ans) {
                cout << i <<' ';
            }
            cout << '\n';
            exit(0);
        }
        else {
            fr[i] = now;
            dfs(i, now);
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
        if (!fr[i]) {
            dfs(i,i);
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
