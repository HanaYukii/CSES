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
vector<pair<int,int>>g[100005];
void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    f(m) {
        int x, y, d;
        cin >> x >> y >> d;
        g[x].pb({y,d});
    }
    ll dis[n + 5][2];
    memset(dis, 0x3f,sizeof(dis));
    dis[1][0] = 0;
    priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>>pq;
    pq.push({0,{1,0}});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (dis[now.S.F][now.S.S] != now.F) {
            continue;
        }
        for (auto &i : g[now.S.F]) {
            if (now.F + i.S < dis[i.F][now.S.S]) {
                dis[i.F][now.S.S] = now.F + i.S;
                pq.push({dis[i.F][now.S.S],{i.F,now.S.S}});
            }
            if (now.S.S == 0) {
                if (now.F + i.S/2 < dis[i.F][1]) {
                    dis[i.F][1] = now.F + i.S/2;
                    pq.push({dis[i.F][1],{i.F,1}});
                }
            }
        }
    }
    cout << dis[n][1] << '\n';
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