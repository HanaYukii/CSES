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
    int n;
    cin >> n;
    vector<int>v;
    f(n) {
        int x;
        cin >> x;
        v.pb(x);
    }
    int mid = n / 2;
    nth_element(v.begin(),v.begin() + mid,v.end());
    ll ans = 0;
    f(n) {
        ans += abs(v[i] - v[mid]);
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