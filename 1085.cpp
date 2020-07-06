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
vector<ll>v;
int m;
bool check(ll x) {
    int cnt = 1;
    ll cur = 0;
    for (auto &i : v) {
        if (i > x) {
            return 0;
        }
        if (cur + i <= x) {
            cur += i;
        }
        else {
            cnt++;
            cur = i;
        }
    }
    return cnt <= m;
}
void solve() {
    ll n;
    cin >> n >> m;
    ll s = 0;
    f(n) {
        int x;
        cin >> x;
        v.pb(x);
        s += x;
    }
    ll l = 0, r = s;
    while (r - l > 1) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << endl;
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