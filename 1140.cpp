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
vector<int>d;
int getID(int x) {
    return lower_bound(all(d),x) - d.begin() + 1;
}
void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>>v;
 
    f(n) {
        int x, y, c;
        cin >> x >> y >> c;
        v.pb({{y,x},c});
        d.pb(x);
        d.pb(y);
    }
    sort(all(d));
    d.erase(unique(all(d)),d.end());
    int ptr = 0;
    ll dp[n * 2 + 5] = {};
    ll mx = 0;
    sort(all(v));
    for (auto &i : v) {
        i.F.F = getID(i.F.F);
        i.F.S = getID(i.F.S);
        int tar = i.F.S - 1;
        while (ptr < tar) {
            dp[ptr + 1] = max(dp[ptr], dp[ptr + 1]);
            ptr++;
        }
        dp[i.F.F] = max(dp[i.F.F], dp[tar] + i.S);
        mx = max(mx, dp[i.F.F]);
    }
    cout << mx << '\n';
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