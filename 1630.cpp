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
    ll n, k;
    cin >> n >> k;
    vector<ll>v;
    f(n) {
        int x;
        cin >> x;
        v.pb(x);
    }
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll mid = (l + r) >> 1;
        ll sum = 0;
        for (auto &i : v) {
            sum += mid / i;
            if (sum >= k) {
                break;
            }
        }
        if (sum >= k) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << '\n';
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