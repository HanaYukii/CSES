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
const int maxn = 3e6+5;
vector<int>g[100005];
int in[100005];
void solve() {
    int n, m;
    cin >> n >> m;
    f (m) {
        int x, y;
        cin >> x >> y;
        g[y].pb(x);
        in[x]++;
    }
    priority_queue<int>pq;
    f1(n) {
        if (!in[i]) pq.push(i);
    }
    vector<int>ans;
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        ans.pb(now);
        for (auto &i : g[now]) {
            in[i]--;
            if (!in[i]) {
                pq.push(i);
            }
        }
    }
    reverse(all(ans));
    for (auto &i : ans) {
        cout << i << ' ';
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