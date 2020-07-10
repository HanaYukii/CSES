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
    int n, m;
    string s1, s2;
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    int dp[n + 1][m + 1];
    dp[0][0] = 0;
    f1(n) {
        dp[i][0] = i;
    }
    f1(m) {
        dp[0][i] = i;
    }
    f1(n) {
        fr(j,1,m+1) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({dp[i - 1][j - 1],dp[i][j - 1], dp[i - 1][j]}) + 1;
            }
        }
    }
    cout << dp[n][m] << '\n';
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