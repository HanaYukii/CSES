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
int dp[505][505];
 
int DP(int x, int y) {
    if (~dp[x][y]) {
        return dp[x][y];
    }
    if (x == y) {
        return dp[x][y] = 1;
    }
    dp[x][y] = 500;
    for (int i = 1 ; i <= x / 2; i++) {
        dp[x][y] = min(dp[x][y], DP(i, y) + DP(x - i, y));
    }
    for (int i = 1 ; i <= y / 2; i++) {
        dp[x][y] = min(dp[x][y], DP(x, i) + DP(x, y - i));
    }
    return dp[x][y];
}
void solve() {
    int x, y;
    cin >> x >> y;
    memset(dp, -1, sizeof(dp));
    cout << DP(x, y) - 1 << '\n';;
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