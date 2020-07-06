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
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll>v{0};
    f(n) {
        ll x;
        cin >> x;
        v.pb(v.back() + x);
    }
    deque<int>dq;
    dq.push_back(0);
    ll ans = -1e18;
    for (int i = a ; i <= n ; i++) {
        ans = max(ans, v[i] - v[dq.front()]);
        if (dq.size() && dq.front() <= i - b) {
            dq.pop_front();
        }
        while (dq.size() && v[dq.back()] > v[i-a+1]) {
            dq.pop_back();
        }
        dq.push_back(i-a+1);
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