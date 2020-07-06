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
    map<int,int>mp;
    int l = 0;
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        int x;
        cin >> x;
        if (mp.count(x)) {
            l = max(l, mp[x]);
        }
        mp[x] = i;
        ans = max(ans ,i - l);
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