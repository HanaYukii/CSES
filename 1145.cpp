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
int dp[505][63000];
 
void solve() {
    int n;
    cin >> n;
    vector<int>v;
    int x;
    cin >> x;
    v.pb(x);
    f(n - 1) {
        int x;
        cin >> x;
        if (x > v.back()) {
            v.pb(x);
        }
        else {
            *lower_bound(all(v), x) = x;
        }
    }
    cout << v.size() << '\n';
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