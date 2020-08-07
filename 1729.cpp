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
    int n, k;
    cin >> n >> k;
    int ans[n + 5] = {};
    ans[0] = 0;
    vector<int>v(k);
    for (auto &i : v) {
        cin >> i;
    }
    f1(n) {
        int mi = 1;
        for (auto &j : v) {
            if (i >= j) {
                mi = min(mi, ans[i - j]);
            }
        }
        ans[i] = mi ^ 1;
        if (ans[i]) {
            cout << 'W';
        }
        else {
            cout << 'L';
        }
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