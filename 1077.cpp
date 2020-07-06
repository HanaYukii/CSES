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
ll b[300000][2];
vector<ll>v;
vector<ll>d;
int getID(int x) {
    return lower_bound(all(d), x) - d.begin() + 1;
}
void update(int x, int id, int dd) {
    //cout << x << endl;
    while (x <= (1<<18)) {
        b[x][id] += dd;
        x += x & (-x);
    }
}
ll get(int x) {
    int cur = 0;
    int nd = x;
    ll sm = 0;
    ll bg = 0;
    ll smc = 0;
    ll bgc = 0;
    for (int i = 17 ; i >= 0 ; i--) {
        if (b[cur+(1<<i)][0] < nd) {
            nd -= b[cur + (1<<i)][0];
            sm += b[cur + (1<<i)][1];
            smc += b[cur + (1<<i)][0];
            cur += (1<<i);
        }
    }
    bgc = b[1<<18][0] - smc;
    bg = b[1<<18][1] - sm;
    //cout << bg <<' '<<bgc <<' '<<d[cur] <<' '<<smc <<' '<<sm<<endl;
    return bg - bgc * d[cur] + d[cur] * smc - sm;
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
    vector<ll>ans;
    for (int i = 0 ; i < k ; i++) {
        update(getID(v[i]),0, 1);
        update(getID(v[i]), 1, v[i]);
    }
    ans.pb(get(tar));
    for (int i = k ; i < n ; i++) {
        update(getID(v[i]), 0, 1);
        update(getID(v[i - k]), 0, -1);
        update(getID(v[i]), 1, v[i]);
        update(getID(v[i - k]), 1, -v[i - k]);
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