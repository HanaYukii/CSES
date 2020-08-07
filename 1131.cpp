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
int dp[maxn];
vector<int>g[maxn];
int mx;
void dfs(int now, int pre = 0) {
    dp[now] = 1;
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        dfs(i, now);
        dp[now] = max(dp[now], dp[i] + 1);
    }
}
void dfs2(int now, int pre = 0, int from = 0) {
    multiset<int>st;
    st.insert(from);
    st.insert(0);
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        st.insert(dp[i]);
    }
    mx = max(mx, *(--st.end()) + * (prev(--st.end())));
    for (auto &i : g[now]) {
        if (i == pre) continue;
        st.erase(dp[i]);
        dfs2(i, now, *(--st.end()) + 1);
        st.insert(dp[i]);
    }
}
void solve() {
    int n;
    cin >> n;
    f (n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    dfs2(1);
    cout << mx << '\n';
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