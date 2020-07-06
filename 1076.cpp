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
int b[300000];
vector<int>v;
vector<int>d;
int getID(int x) {
    return lower_bound(all(d), x) - d.begin() + 1;
}
void update(int x, int dd) {
    //cout << x << endl;
    while (x < (1<<18)) {
        b[x] += dd;
        x += x & (-x);
    }
}
int get(int x) {
    int cur = 0;
    int nd = x;
    for (int i = 17 ; i >= 0 ; i--) {
        if (b[cur+(1<<i)] < nd) {
            nd -= b[cur + (1<<i)];
            cur += (1<<i);
        }
    }
    return d[cur];
}
void solve() {
    int n, k;
    cin >> n >> k;
    f(n) {
        int x;
        cin >> x;
        v.pb(x);
        d.pb(x);
    }
    sort(all(d));
    d.erase(unique(all(d)),d.end());
    int tar = (k + 1) / 2;
    vector<int>ans;
    for (int i = 0 ; i < k ; i++) {
        update(getID(v[i]), 1);
    }
    ans.pb(get(tar));
    for (int i = k ; i < n ; i++) {
        update(getID(v[i]), 1);
        update(getID(v[i - k]), -1);
        ans.pb(get(tar));
    }
    for (auto &i : ans) {
        cout << i <<' ';
    }
    cout << '\n';
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