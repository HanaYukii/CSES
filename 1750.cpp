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
const int maxn = 2000005;
int pa[200005][30];
int getpa(int x, int p) {
    int cur = 0;
    int ret = x;
    while (p) {
        if (p & 1) {
            ret = pa[ret][cur];
        }
        p >>= 1;
        cur++;
    }
    return ret;
}
void solve() {
    int n, q;
    cin >> n >> q;
    f1(n) {
        cin >> pa[i][0];
    }
    f1(29) {
        fr(j,1,n+1) {
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    while (q--) {
        int x, p;
        cin >> x >> p;
        cout << getpa(x, p) << '\n';
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