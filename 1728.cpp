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
const int maxn = 200005;
 
void solve() {
    int n;
    cin >> n;
    int v[n + 5] = {};
    f1 (n) {
        cin >> v[i];
    }
    double ans = 0;
    f1(n) {
        fr(j,i + 1,n+1) {
            double pool = v[i] * v[j];
            double can = 0;
            for (int k = 1 ; k <= v[i] ; k++) {
                can += min(v[j],k-1);
            }
            ans += can / pool;
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';
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