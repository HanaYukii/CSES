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
int v[200005];
void solve() {
    int n;
    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        ll ans = (i * i) * (i * i - 1) / 2;
        ans -= 4 * (i - 1) * (i - 2);
        cout << ans << '\n';
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