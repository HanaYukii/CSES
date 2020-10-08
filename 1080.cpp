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
string s;
int n;
ll dp[505][505];
ll pre[maxn];
ll inv[maxn];
ll prei[maxn];
void build(int n){
    pre[1] = pre[0] = 1, inv[1] = inv[0] = 1, prei[1] = prei[0] = 1;
    for(int i = 2 ; i <= n ; i++){
        pre[i] = pre[i-1] * i % mod;
        inv[i] = (mod - mod / i * inv[mod % i] % mod) % mod;
        prei[i] = prei[i-1] * inv[i] % mod;
    }
}
ll C(int n, int k){
   return pre[n] * prei[k] % mod * prei[n-k] % mod;
}
ll solve(int l, int r) {
    if (~dp[l][r]) {
        return dp[l][r];
    }
    if (l > r) {
        return dp[l][r] = 1;
    }
    ll ans = 0;
    for(int i = l + 1 ; i <= r ; i++) {
        if (s[i] == s[l]) {
            int left = (i - l + 1) / 2;
            int tot = (r - l + 1) / 2;
            ans += solve(l + 1, i - 1) * solve(i + 1, r) % mod * C(tot, left) % mod;
            ans %= mod;
        }
    }
    return dp[l][r] = ans;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> s;
    n = s.size();
    build(n);
    cout << solve(0,s.size() - 1) << '\n';
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