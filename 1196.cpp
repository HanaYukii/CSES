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
vector<pair<int,int>>g[100005];
vector<ll>ans[100005];
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    f(m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,1});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (ans[now.S].size() == k) {
            continue;
        }
        ans[now.S].pb(now.F);
        for (auto &i : g[now.S]) {
            pq.push({now.F + i.S, i.F});
        }
    }
    for (auto &i : ans[n]) {
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
