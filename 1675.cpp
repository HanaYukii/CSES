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
const int maxn = 200005;
int d[maxn];
int fi(int x) {
    return d[x] == x ? x : d[x] = fi(d[x]);
}
void solve() {
    int n, m;
    cin >> n >> m;
    f1(n) {
        d[i] = i;
    }
    ll ans = 0;
    vector<pair<int,pair<int,int>>>v;
    f(m) {
        int x, y, c;
        cin >> x >> y >> c;
        v.pb({c,{x,y}});
    }
    sort(all(v));
    for (auto &i : v) {
        int x = i.S.F;
        int y = i.S.S;
        int c = i.F;
        x = fi(x);
        y = fi(y);
        if (x != y) {
            ans += c;
            d[x] = y;
            n--;
        }
    }
    if (n != 1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << ans << '\n';
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
