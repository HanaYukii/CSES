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
vector<int>d;
int n;
int getID(int x) {
    return lower_bound(all(d), x) - d.begin() + 1;
}
int b[maxn];
void update(int x) {
    while (x <= n) {
        b[x]++;
        x += x & (-x);
    }
}
int query(int x) {
    int ret = 0;
    while (x) {
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
void solve() {
    cin >> n;
    vector<int>v(n);
    for (auto &i : v) {
        cin >> i;
        d.pb(i);
    } 
    
    sort(all(d));
    for (auto &i : v) {
        i = getID(i);
    }
    ll ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int tot = n - v[i];
        int cur = i - query(v[i]);
        ans += min(cur,tot-cur);
        update(v[i]);
    }
    cout << ans << '\n';
}
int main() {
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