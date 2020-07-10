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
    int dp[x+1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    f1(n) {
        int a;
        cin >> a;
        for (int j = 0 ; j <= x - a ; j++) {
            dp[j + a] = min(dp[j + a], dp[j] + 1);
        }
    }
    if (dp[x] > x) {
        dp[x] = -1;
    }
    cout << dp[x] << '\n';
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