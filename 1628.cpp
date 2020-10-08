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
int tar;
map<int,int> build(vector<int>v) {
    map<int,int>mp;
    mp[0] = 1;
    for (int i = 1 ; i < (1<<v.size()) ; i++) {
        ll sum = 0;
        for (int j = 0 ; j < v.size() ; j++) {
            if ((1<<j)&i) {
                sum += v[j];
            }
        }
        if (sum <= tar) {
            mp[sum]++;
        }
    }
    return mp;
}
void solve() {
    int n;
    cin >> n >> tar;
    vector<int>v1,v2;
    f(n/2) {
        int x;
        cin >> x;
        v1.pb(x);
    }
    for (int i = n/2; i < n ; i++) {
        int x;
        cin >> x;
        v2.pb(x);
    }
    random_shuffle(all(v1));
    random_shuffle(all(v2));
    auto m1 = build(v1);
    auto m2 = build(v2);
    ll ans = 0;
    for (auto &i : m1) {
        if (m2.count(tar - i.F)) {
            ans += (ll)i.S * m2[tar-i.F];
        }
    }
    cout << ans << '\n';
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