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
int pa[200005][18];
int getpa(int x, int p) {
    int cur = x;
    for (int i = 17 ; i >= 0 ; i--) {
        if (p & (1<<i)) {
            cur = pa[cur][i];
        }
    }
    if (cur == 0) {
        cur--;
    }
    return cur;
}
void solve() {
    int n, q;
    cin >> n >> q;
    pa[1][0] = 0;
    fr(i,2,n+1) {
        int x;
        cin >> x;
        pa[i][0] = x;
    }
    f1(17) {
        fr(j,1,n+1) {
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << getpa(x, y) << '\n';
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