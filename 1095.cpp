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
int pm(ll x, ll p) {
    ll ret = 1;
    ll now = x;
    while (p) {
        if (p & 1) {
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        p >>= 1;
    }
    return ret;
}
 
void solve() {
    int a, b;
    cin >> a >> b;
    cout << pm(a, b) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}