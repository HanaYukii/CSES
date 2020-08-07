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
const int maxn = 2000005;
 
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    double dp[n + 1][n * 6 + 5];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    f(n) {
        fr(j,0,n*6) {
            fr(k,1,7) {
                dp[i+1][j+k] += dp[i][j] / 6.0;
            }
        }
    }
    double ans = 0;
    for (int i = a ; i <= b; i ++) {
        ans += dp[n][i];
    }
    cout << fixed << setprecision(6) << ans << '\n';
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
