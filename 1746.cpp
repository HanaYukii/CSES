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
    int n, x;
    cin >> n >> x;
    int dp[n + 1][x+1] = {};
    int v[n];
    f(n) {
        cin >> v[i];
    }
    if (v[0] == 0) {
        f1(x) {
            dp[0][i] = 1;
        }
    }
    else {
        dp[0][v[0]] = 1;
    }
    for (int i = 1 ; i < n ; i++) {
        if (v[i] == 0) {
            fr(j,1,x+1) {
                fr(k,-1,2) {
                    dp[i][j] += dp[i-1][j + k];
                    dp[i][j] %= mod;
                }
            }
        }
        else {
            fr(k,-1,2) {
                dp[i][v[i]] += dp[i-1][v[i]+k];
                dp[i][v[i]] %= mod;
            }
        }
    }
    int ans = 0;
    f1(x) {
        ans += dp[n - 1][i];
        ans %= mod;
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
