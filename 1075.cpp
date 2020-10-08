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
 
void solve() {
    int n;
    cin >> n;
    vector<long long>ans{1,1,0,0};
    while(ans.size() <= n) {
        ans.push_back(ans.back() * (ans.size() + 1) - ans[ans.size()-2] * (ans.size() - 2) - ans[ans.size() - 3] * (ans.size() - 5) + ans[ans.size() - 4] * (ans.size() - 3));
        ans.back() %= mod;
        if (ans.back() < 0) {
            ans.back() += mod;
        }
    }
    if (ans[n] < 0) {
        ans[n] += mod;
    }
    cout << ans[n] << '\n';
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