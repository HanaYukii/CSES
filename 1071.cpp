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
int v[200005];
void solve() {
    ll x, y;
    cin >> x >> y;
    ll c = max(x, y);
    ll bs = (c - 1) * (c - 1);
    ll tm = 0;
    if (c % 2 == 0) {
        if (y == c) {
            tm = x;
        }
        else {
            tm = x * 2 - y;
        }
    }
    else {
        if (x == c) {
            tm = y;
        }
        else {
            tm = y * 2 - x;
        }
    }
    cout << bs + tm << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}