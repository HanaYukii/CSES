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
vector<int>g[maxn][2];
ll dfs(int now,int pre,int tp){
    ll ret = 1;
    vector<ll>v;
    for(auto i:g[now][tp]){
        if( i == pre)continue;
        v.pb(dfs(i,now,tp));
    }
    sort(v.rbegin(),v.rend());
    for(auto i:v){
        ret *= 6171;
        ret += i;
        ret %= mod;
    }
    return ret;
}
ll dfs2(int now,int pre,int tp){
    ll ret = 31;
    vector<ll>v;
    for(auto i:g[now][tp]){
        if( i == pre)continue;
        v.pb(dfs2(i,now,tp));
    }
    sort(v.rbegin(),v.rend());
    for(auto i:v){
        ret *= 97;
        ret += i;
        ret %= mod;
    }
    return ret;
}
void solve() {
    int n;
    cin >> n;
    f1(n) {
        g[i][0].clear();
    }
    f(n - 1) {
        int x, y;
        cin >> x >> y;
        g[x][0].pb(y);
        g[y][0].pb(x);
    }
    f1(n) {
        g[i][1].clear();
    }
    f(n - 1) {
        int x, y;
        cin >> x >> y;
        g[x][1].pb(y);
        g[y][1].pb(x);
    }
    if (dfs(1,1,0) == dfs(1,1,1) && dfs2(1,1,0) == dfs2(1,1,1)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 1;
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