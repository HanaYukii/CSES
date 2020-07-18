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
int dfn[200005];
int low[200005];
int stk[200005];
int pa[200005];
int scc;
int idx;
stack<int>st;
vector<int>g[200005];
void tarjan(int now) {
    dfn[now] = low[now] = ++idx;
    stk[now] = 1;
    st.push(now);
    for (auto &i : g[now]) {
        if (!dfn[i]) {
            tarjan(i);
            low[now] = min(low[now], low[i]);
        }
        else if (stk[i]) {
            low[now] = min(low[now], dfn[i]);
        }
    }
    if (dfn[now] == low[now]) {
        scc++;
        int nxt =-1;
        while (nxt != now) {
            nxt = st.top();
            st.pop();
            stk[nxt] = 0;
            pa[nxt] = scc;
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
    }
    f1(n) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    cout << scc << '\n';
    f1(n) {
        cout << pa[i] << ' ';
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