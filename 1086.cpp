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
const int maxn = 3e6+5;
ll cal(ll x) {
    ll ret = 0;
    ll now = 10;
    for (int i = 0 ; i < 18 ; i++) {
        ret += x / now * (now / 10);
        ret += max(0LL,min(x % now - now / 10 + 1, now / 10));
        now *= 10;
    }
    //cout << x <<' '<<ret << endl;
    return ret;
}
void solve() {
    ll x;
    cin >> x;
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll mid = (l + r) >> 1;
        if (cal(mid) <= x) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << '\n';
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