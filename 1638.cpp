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
    int n;
    cin >> n;
    string s[n];
    int dp[n + 5][n + 5] = {};
    f(n) {
        cin >> s[i];
    }
    if (s[0][0] == '*') {
        cout << 0 << '\n';
        exit(0);
    }
    dp[0][0] = 1;
    f1(n - 1) {
        if (s[0][i] == '.') {
            dp[0][i] = dp[0][i - 1];
        }
        if (s[i][0] == '.') {
            dp[i][0] = dp[i - 1][0];
        }
    }
    f1(n - 1) {
        fr(j,1,n) {
            if (s[i][j] == '.') {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            }
        }
    }
    cout << dp[n - 1][n - 1] << '\n';
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