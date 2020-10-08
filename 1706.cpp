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
const int maxn = 2e5+5;
bitset<100001>b;
int d[maxn];
int fi(int x) {
    return d[x] < 0 ? x : d[x] = fi(d[x]);
}
void solve() {
    memset(d, -1, sizeof(d));
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        x = fi(x);
        y = fi(y);
        if (x != y) {
            d[x] += d[y];
            d[y] = x;
        }
    }
    b.reset();
    b.set(0);
    f1(n) {
        if (d[i] < 0) {
            b |= (b << (-d[i]));
        }
    }
    f1(n) {
        cout << b[i];
    }
    cout << '\n';
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