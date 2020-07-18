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
vector<int>g[100005];
int in[100005];
void solve() {
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        in[y]++;
    }
    queue<int>q;
    vector<int>ans;
    f1(n) {
        if (!in[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        int now = q.front();
        q.pop();
        ans.pb(now);
        for (auto &i : g[now]) {
            in[i]--;
            if (!in[i]) {
                q.push(i);
            }
        } 
    }
    if (ans.size() != n) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
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