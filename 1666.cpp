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
const int maxn = 1000005;
int d[maxn];
int fi(int x) {
    return d[x] == x ? x : d[x] = fi(d[x]);
}
void solve() {
    int n, m;
    cin >> n >> m;
    f1(n) {
        d[i] = i;
    }
    f (m) {
        int x, y;
        cin >> x >> y;
        x = fi(x);
        y = fi(y);
        d[x] = y;
    }
    vector<int>tar;
    f1(n - 1) {
        if (fi(i) != fi(n)) {
            tar.pb(i);
            d[fi(i)] = fi(n);
        }
    }
    cout << tar.size() << '\n';
    for (auto &i : tar) {
        cout << i <<' '<<n << '\n';
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