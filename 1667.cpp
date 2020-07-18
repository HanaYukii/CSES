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
void solve() {
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int fr[n + 5] = {};
    queue<int>q;
    q.push(1);
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (auto &i : g[now]) {
            if (!fr[i]) {
                fr[i] = now;
                q.push(i);
            }
        }
    }
    if (!fr[n]) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        vector<int>ans{n};
        while(ans.back()!=1) {
            ans.pb(fr[ans.back()]);
        }
        reverse(all(ans));
        cout << ans.size() << '\n';
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
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