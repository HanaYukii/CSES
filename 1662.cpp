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
    map<ll,int>mp;
    mp[0] = 1;
    ll n;
    cin >> n;
    ll cur = 0;
    ll ans = 0;
    f (n) {
        int x;
        cin >> x;
        x %= n;
        x += n;
        x %= n;
        cur += x;
        cur %= n;
        if (mp.count(cur)) {
            ans += mp[cur];
        }
        mp[cur]++;
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