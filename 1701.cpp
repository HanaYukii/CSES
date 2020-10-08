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
vector<int>cen[2];
int sz[maxn][2];
int n;
void dfs3(int now, int pre, int tp) {
    sz[now][tp] = 1;
    int mx = 0;
    for (auto &i : g[now][tp]) {
        if (i == pre) continue;
        dfs3(i,now,tp);
        sz[now][tp] += sz[i][tp];
        mx = max(mx, sz[i][tp]);
    }
    mx = max(mx, n - sz[now][tp]);
    if (mx <= n / 2) {
        cen[tp].pb(now);
    }
}
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
ll dfs4(int now,int pre,int tp){
    ll ret = 61;
    vector<ll>v;
    for(auto i:g[now][tp]){
        if( i == pre)continue;
        v.pb(dfs4(i,now,tp));
    }
    sort(v.begin(),v.end());
    for(auto i:v){
        ret *= 29;
        ret += i;
        ret %= mod;
    }
    return ret;
}
ll dfs5(int now,int pre,int tp){
    ll ret = 831;
    vector<ll>v;
    for(auto i:g[now][tp]){
        if( i == pre)continue;
        v.pb(dfs5(i,now,tp));
    }
    sort(v.begin(),v.end());
    for(auto i:v){
        ret *= 817;
        ret += i;
        ret %= mod;
    }
    return ret;
}
void solve() {
    memset(sz,0,sizeof(sz));
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
    cen[0].clear();
    cen[1].clear();
    dfs3(1,0,0);
    dfs3(1,0,1);
    if (cen[0].size() != cen[1].size()) {
        cout << "NO\n";
        return;
    }
 
    vector<int>ans1,ans2;
    for (auto &i : cen[0]) {
        ans1.pb(dfs(i,0,0));
        ans1.pb(dfs2(i,0,0));
        ans1.pb(dfs4(i,0,0));
        ans1.pb(dfs5(i,0,0));
    }
    for (auto &i : cen[1]) {
        ans2.pb(dfs(i,0,1));
        ans2.pb(dfs2(i,0,1));
        ans2.pb(dfs4(i,0,1));
        ans2.pb(dfs5(i,0,1));
    }
    sort(all(ans1));
    sort(all(ans2));
    if (ans1 == ans2) {
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