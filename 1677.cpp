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
vector<pair<int,int>>ans;
int d[maxn];
int fi(int x) {
    return d[x] == x ? x : d[x] = fi(d[x]);
}
void solve() {
    set<pair<int,int>>st;
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>>rev;
    f1 (n) {
        d[i] = i;
    }
    f(m) {
        int x, y;
        cin >> x >> y;
        st.insert({x,y});
    }
    f(k) {
        int x, y;
        cin >> x >> y;
        rev.pb({x,y});
        st.erase({x,y});
        st.erase({y,x});
    }
    reverse(all(rev));
    int ans = n;
    for (auto &i : st) {
        int x = fi(i.F);
        int y = fi(i.S);
        if (x != y) {
            ans--;
            d[x] = y;
        }
    }
    vector<int>ret;
    for (auto &i : rev) {
        ret.pb(ans);
        int x = fi(i.F);
        int y = fi(i.S);
        if (x != y) {
            ans--;
            d[x] = y;
        }
    }
    reverse(all(ret));
    for (auto &i : ret) {
        cout << i << ' ';
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