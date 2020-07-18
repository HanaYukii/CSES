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
set<int>st[100005];
vector<int>ans;
void dfs(int now) {
    while (st[now].size()) {
        int x = *st[now].begin();
        st[now].erase(x);
        st[x].erase(now);
        dfs(x);
    }
    ans.pb(now);
}
void solve() {
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        st[x].insert(y);
        st[y].insert(x);
    }
    f1(n) {
        if (st[i].size() & 1) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }
    dfs(1);
    
    if (ans.size() != m + 1 || ans[0] != 1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
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