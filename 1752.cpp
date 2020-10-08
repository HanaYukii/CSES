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
const int sq = 505;
int n, d;
vector<int>g[maxn];
int u[maxn], dep[maxn];
int u2[sq][maxn];
int f = 0;
int pa[200005][18];
void dfs1(int now, int pre = 0){
    pa[now][0] = pre;
    for(auto i:g[now]){
        if (i == pre) {
            continue;
        }
        dep[i] = dep[now] + 1;
        dfs1(i, now);
    }
}
int lca(int x,int y){
    if(dep[x] < dep[y]){
        swap(x,y);
    }
    int left = dep[x] - dep[y];
    for(int i=17;i>=0;i--){
        if(left >= (1<<i)){
            x = pa[x][i];
            left -= (1<<i);
        }
    }
    if(x==y)return x;
    for(int i=17;i>=0;i--){
        if(pa[x][i]!=pa[y][i]){
            x = pa[x][i];
            y = pa[y][i];
        }
    }
    return pa[x][0];
}
int dis(int x,int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
void dfs2(int now, int dd, int pre = -1) {
    if (dd == 0) 
        return;
    u[now] = 1;
    u2[dd][now] = 1;
    for (auto i : g[now]) {
        if ((u2[dd - 1][i] == 1) || i == pre) continue;
        dfs2(i, dd - 1, now);
    }
}
 
void solve() {
    cin >> n >> d;
    if (d < sq) {
        f = 1;
    }
    vector <pair <int, int>> v;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1);
    for(int i = 1 ; i <= n ; i++) {
        v.push_back({dep[i], i});
    }
    f1(17) {
        fr(j,1,n+1) {
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    sort(v.rbegin(), v.rend());
    vector<int>ans;
    if (f) {
        for (auto i : v) {
            if (u[i.S] == 1) continue;
            ans.push_back(i.S);
            dfs2(i.S, d);
        }
    }
    else {
        for (auto &i : v) {
            int f = 0;
            for (auto &j : ans) {
                if (dis(i.S,j) < d) {
                    f = 1;
                    break;
                }
            }
            if (!f) {
                ans.pb(i.S);
                random_shuffle(all(ans));
                //cout << i.S << endl;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto &i : ans) {
        cout << i <<' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test_input.txt","r",stdin);
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