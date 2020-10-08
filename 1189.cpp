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
const int maxn = 2005;
 
 
void solve() {
    int n;
    cin >> n;
    ll a[n + 5], b[n + 5];
    vector<ll>v;
    f1(n) {
        cin >> a[i];
    }
    f1(n) {
        cin >> b[i];
    }
    v.pb(0);
    for (int i = 1 ; i < n ; i++) {
        v.pb(a[i] - b[i]);
        a[i + 1] += v.back();
    }
    sort(all(v));
    ll mid = v[n/2];
    ll ans = 0;
    for (auto &i : v) {
        ans += abs(i - mid);
    }
    cout << ans << '\n';
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