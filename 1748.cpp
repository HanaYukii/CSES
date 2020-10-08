#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define pll pair<ll,ll>
#define pii pair<int,int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
vector<int>d;
int b[maxn];
void update(int x, int dd) {
    while (x <= d.size()) {
        b[x] += dd;
        b[x] %= mod;
        x += x & (-x);
    }
}
int query(int x) {
    int ret = 0;
    while (x) {
        ret += b[x];
        ret %= mod;
        x -= x & (-x);
    }
    return ret;
}
int getID(int x) {
    return lower_bound(all(d),x)-d.begin() + 1;
}
void solve() {
    int n;
    cin >> n;
    int v[n + 5];
    f1(n) {
        cin >> v[i];
        d.pb(v[i]);
    }
    sort(all(d));
    d.erase(unique(all(d)),d.end());
    update(getID(v[1]),1);
    fr(i,2,n+1) {
        int x = query(getID(v[i])-1);
        update(getID(v[i]),x + 1);
    }
    cout << query(d.size()) << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
