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
    vector<int>v;
    int n, m;
    cin >> n >> m;
    f(n) {
        int x;
        cin >> x;
        v.pb(x);
    }
    sort(all(v));
    int ans = n;
    int p1 = 0, p2 = n - 1;
    while (p1 < p2) {
        if (v[p1]+v[p2] <= m) {
            ans--;
            p1++, p2--;
        }
        else {
            p2--;
        }
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