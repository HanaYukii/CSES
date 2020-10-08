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
int n;
int v[maxn];
int b[maxn];
int o[maxn];
void update(int x) {
    while (x <= n) {
        b[x]++;
        x += x & (-x);
    }
}
int query(int x) {
    int ret = 0;
    while (x) {
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
void s1() {
    ll ans = 0;
    f1 (n) {
        ans += i - 1 - query(v[i]);
        update(v[i]);
    }
    cout << ans << ' ';
}
void s2 () {
    int ans = 0;
    f1(n) {
        while(v[i] != i) {
            ans++;
            swap(v[i],v[v[i]]);
        }
    }
    f1(n) {
        v[i] = o[i];
    }
    cout << ans << ' ';
}
void s3 () {
    vector<int>LIS{v[1]};
    fr(i,2,n+1) {
        if (v[i] > LIS.back()) {
            LIS.pb(v[i]);
        }
        else {
            *lower_bound(all(LIS),v[i]) = v[i];
        }
    }
    cout << n - LIS.size() << ' ';
}
void s4 () {
    int ans = n;
    for (int i = n ; i >= 1 ; i--) {
        if (v[i] == ans) {
            ans--;
        }
    }
    cout << ans << '\n';
}
void solve() {
    cin >> n;
    f1(n) {
        cin >> v[i];
        o[i] = v[i];
    }
    s1();
    s2();
    s3();
    s4();
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