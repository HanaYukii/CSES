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
int n;
ll v[5005];
ll dp[5005][5005];
ll DP(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (~dp[l][r]) {
        return dp[l][r];
    }
    if ((n - r - l + 1) % 2 == 0) {
        dp[l][r] = max(v[l] + DP(l + 1, r), v[r] + DP(l, r - 1));
    }
    else {
        dp[l][r] = min(DP(l + 1, r), DP(l, r - 1));
    }
    return dp[l][r];
}
void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    f1(n) {
        cin >> v[i];
    }
    cout << DP(1, n) << '\n';
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