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
const int maxn = 3e6+5;
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll dp[n + 5] = {1};
    int last[26] = {};
    ll sum = 1;
    f1(s.size()) {
        int x = s[i - 1] - 'a';
        dp[i] = sum * 2 % mod;
        if (last[x]) {
            dp[i] -= dp[last[x]-1];
            dp[i] += mod;
            dp[i] %= mod;
        }
        sum = dp[i];
        last[x] = i;
    }
    sum += mod - 1;
    sum %= mod;
    cout << sum << '\n';
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