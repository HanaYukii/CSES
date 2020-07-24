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
 
vector<int>d;
int ans[200005];
int cnt[200005];
int v[200005];
int sq;
struct q
{
    int id;
    int l, r;
    int lbk;
};
bool cmp(q x, q y) {
    if (x.lbk == y.lbk) {
        return x.r < y.r;
    }
    else {
        return x.lbk < y.lbk;
    }
}
vector<q>p;
int cur;
void add(int x) {
    cnt[v[x]]++;
    if (cnt[v[x]] == 1) {
        cur++;
    }
}
void rem(int x) {
    cnt[v[x]]--;
    if (cnt[v[x]] == 0) {
        cur--;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    sq = (int)sqrt(n);
    f1(n) {
        cin >> v[i];
        d.pb(v[i]);
    }
    sort(all(d));
    d.erase(unique(all(d)),d.end());
    f1(n) {
        v[i] = lower_bound(all(d), v[i]) - d.begin();
    }
    f1(m) {
        int l, r;
        cin >> l >> r;
        p.pb({i,l,r,(l-1)/sq});
    }
    sort(all(p),cmp);
    int l = 1, r = 1;
    cur = 1;
    cnt[v[1]] = 1;
    for (auto &i : p) {
        while (r < i.r) {
            add(++r);
        }
        while (l > i.l) {
            add(--l);
        }
        while (l < i.l) {
            rem(l++);
        }
        while (r > i.r) {
            rem(r--);
        }
        ans[i.id] = cur;
    }
    f1(m) {
        cout << ans[i] <<'\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}