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
int v[200005];
int in[200005];
int out[200005];
int dfn;
int ans[200005];
int cnt[200005];
int c[200005];
int sq;
int cur;
struct q {
    int idx;
    int l, r;
    bool operator <(const q &rhs)const {
        if ((l - 1) / sq != (rhs.l -1) / sq) {
            return (l-1)/sq < (rhs.l-1)/sq;
        }
        else {
            return r < rhs.r;
        }
    }
};
void dfs(int now, int pre) {
    in[now] = ++dfn;
    c[dfn] = v[now];
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        dfs(i, now);   
    }
    out[now] = dfn;
}
 
void add(int x) {
    cnt[c[x]]++;
    if (cnt[c[x]] == 1) {
        cur++;
    }
}
void rem(int x) {
    cnt[c[x]]--;
    if (cnt[c[x]] == 0) {
        cur--;
    }
}
vector<int>d;
void solve() {
    int n;
    cin >> n;
    sq = (int)sqrt(n);
    f1 (n) {
        cin >> v[i];
        d.pb(v[i]);
    }
    sort(all(d));
    d.erase(unique(all(d)),d.end());
    f1 (n) {
        v[i] = lower_bound(all(d), v[i]) - d.begin();
    }
    fr(i,2,n+1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,0);
    vector<q>e;
    f1(n) {
        e.pb({i,in[i],out[i]});
    }
    sort(all(e));
    int l = 1, r = 1;
    cur = 1;
    cnt[c[1]] = 1;
    for (auto &i : e) {
        while (l > i.l) {
            add(--l);
        }
        while (r < i.r) {
            add(++r);
        }
        while (r > i.r) {
            rem(r--);
        }
        while (l < i.l) {
            rem(l++);
        }
        ans[i.idx] = cur;
    }
    f1 (n) {
        cout << ans[i] << ' ';
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