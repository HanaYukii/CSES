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
vector<pair<int,int>>g[50000];
vector<int>ans;
void dfs(int now) {
    while (g[now].size()) {
        auto nxt = g[now].back();
        g[now].pop_back();
        dfs(nxt.F);
        ans.pb(nxt.S);
    }
}
void solve() {
    int n;
    cin >> n;
    int a = (1<<(n-1))-1;
    for (int i = 0 ; i < (1<<(n-1)) ; i++) {
        int to = (i<<1) & a;
        g[i].pb({to,0});
        g[i].pb({to+1,1});
    }
    dfs(0);
    f(n-1) {
        ans.pb(0);
    }
    reverse(all(ans));
    for (auto &i :ans) {
        cout << i;
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