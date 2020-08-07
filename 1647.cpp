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
const int maxn = 1e6+5;
int dp[1<<20];
int dp2[1<<20];
int v[1<<20];
void solve() {
    int n;
    cin >> n;
    f1(n) {
        cin >> v[i];
        dp[v[i]]++;
        dp2[v[i]^((1<<20)-1)]++;
    }
    for (int j = 0 ; j < 20 ; j++) {
        fr(i,0,1<<20) {
            if ((i&(1<<j))) {
                dp[i] += dp[i ^ (1<<j)];
                dp2[i] += dp2[i ^ (1<<j)];
            }
        }
    }
    f1(n) {
        cout << dp[v[i]] <<' '<<dp2[v[i]^((1<<20)-1)]<<' '<<n-dp[v[i]^((1<<20)-1)] << '\n';
    }
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