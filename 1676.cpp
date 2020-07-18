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
int d[100005];
int fi(int x) {
    if (d[x] < 0) {
        return x;
    }
    return d[x] = fi(d[x]);
}
void solve() {
    int n, m;
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    int cc = n;
    int mx = 1;
    f(m) {
        int x, y;
        cin >> x >> y;
        x = fi(x);
        y = fi(y);
        if (x != y) {
            cc--;
            d[x] += d[y];
            d[y] = x;
            mx = max(mx, -d[x]);
        }
        cout << cc <<' '<<mx << '\n';
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