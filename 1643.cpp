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
void solve() {
    ll ans = -1e9;
    ll cur = 0;
    int n;
    cin >> n;
    f(n) {
        ll x;
        cin >> x;
        cur += x;
        ans = max(ans, cur);
        cur = max(cur, 0LL);
    }
    cout << ans << '\n';
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