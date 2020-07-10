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
int dp[505][63000];
 
void solve() {
    dp[0][0] = 1;
    int n;
    cin >> n;
    int tar = (n) * (n + 1) / 2;
    if (tar & 1) {
        cout << 0 << endl;
        return;
    }
    tar /= 2;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= tar; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= mod;
            if (j + i + 1 <= tar) {
                dp[i + 1][j + i + 1] += dp[i][j];
                dp[i + 1][j + i + 1] %= mod;
            }
        }
    }
    ll ans = dp[n][tar];
    ans *= 500000004;
    ans %= mod;
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