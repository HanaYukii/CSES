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
    int n, k;
    cin >> n >> k;
    double dp[n + 1][k + 1] = {};
    f1(k) {
        dp[1][i] = 1.0/k;
    }
    f1(n-1) {
        fr(j,1,k+1) {
            fr(z,1,k+1) {
                dp[i + 1][max(j,z)] += dp[i][j] /k;
            }
        }
    }
    double ans = 0;
    f1(k) {
        ans += i * dp[n][i];
    }
    cout << fixed << setprecision(6) <<ans << '\n';
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