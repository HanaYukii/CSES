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
    int n, m, q;
    cin >> n >> m >> q;
    ll dis[n + 5][n + 5];
    memset(dis, 0x3f, sizeof(dis));
    f(m) {
        int x, y;
        ll c;
        cin >> x >> y >> c;
        dis[x][y] = min(dis[x][y], c);
        dis[y][x] = min(dis[y][x], c);
    }
    f1(n) {
        dis[i][i] = 0;
    }
    for (int k = 1 ; k <= n ; k++) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    f1 (q) {
        int x, y;
        cin >> x >> y;
        if (dis[x][y] > 1e15) {
            cout << -1 << '\n';
        }
        else {
            cout << dis[x][y] << '\n';
        }
    }
 
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