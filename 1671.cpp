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
vector<pair<int,int>>g[200005];
 
void solve() {
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].pb({y,c});
    }
    ll dis[n + 5];
    memset(dis, 0x3f,sizeof(dis));
    dis[1] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,1});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (dis[now.S] != now.F) {
            continue;
        }
        for (auto &i :g[now.S]) {
            if (now.F + i.S < dis[i.F]) {
                dis[i.F] = now.F + i.S;
                pq.push({dis[i.F], i.F});
            }
        }
    }
    f1(n) {
        cout << dis[i] <<' ';
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