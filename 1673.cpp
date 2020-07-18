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
const int maxn = 200005;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int,int>,int>>v;
    f(m) {
        int x, y, z;
        cin >> x >> y >> z;
        v.pb({{x,y},z});
    }
    ll dp[n+1] = {};
    int can[n + 1] = {};
    int can2[n + 1] = {};
    can2[1] = 1;
    can[n] = 1;
    memset(dp, 0xc4,sizeof(dp));
    dp[1] = 0;
    for (int z = 0 ; z < n ; z++) {
        for (auto &i : v) {
            if (dp[i.F.F] + i.S >= dp[i.F.S]) {
                dp[i.F.S] = dp[i.F.F] + i.S;
            }
            if (can[i.F.S]) {
                can[i.F.F] = 1;
            }
            if (can2[i.F.F]) {
                can2[i.F.S] = 1;
            }
        }
    }
    ll ans = dp[n];
    for (int z = 0 ; z < n ; z++) {
        for (auto &i : v) {
            if (dp[i.F.F] + i.S > dp[i.F.S] && can[i.F.F] && can2[i.F.F]) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    cout << ans << '\n';
    
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