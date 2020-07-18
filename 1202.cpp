include <bits/stdc++.h>
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
vector<pair<int,int>>g[maxn];
int n;
ll s1() {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    ll d[n + 5];
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    pq.push({0,1});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (d[now.S] != now.F) {
            continue;
        }
        for (auto &i : g[now.S]) {
            if (d[i.F] > now.F + i.S) {
                d[i.F] = now.F + i.S;
                pq.push({d[i.F],i.F});
            }
        }
    }
    return d[n];
}
ll s2() {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    ll d[n + 5];
    ll dp[n + 5] = {};
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    dp[1] = 1;
    pq.push({0,1});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (d[now.S] != now.F) {
            continue;
        }
        for (auto &i : g[now.S]) {
            if (d[i.F] > now.F + i.S) {
                d[i.F] = now.F + i.S;
                pq.push({d[i.F],i.F});
                dp[i.F] = dp[now.S];
            }
            else if (d[i.F] == now.F + i.S) {
                dp[i.F] += dp[now.S];
                dp[i.F] %= mod;
            }
        }
    }
    return dp[n];
}
ll s3() {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    ll d[n + 5];
    ll dp[n + 5] = {};
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    dp[1] = 0;
    pq.push({0,1});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (d[now.S] != now.F) {
            continue;
        }
        for (auto &i : g[now.S]) {
            if (d[i.F] > now.F + i.S) {
                d[i.F] = now.F + i.S;
                pq.push({d[i.F],i.F});
                dp[i.F] = dp[now.S] + 1;
            }
            else if (d[i.F] == now.F + i.S) {
                dp[i.F] = min(dp[now.S] + 1, dp[i.F]);
            }
        }
    }
    return dp[n];
}
ll s4() {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    ll d[n + 5];
    ll dp[n + 5] = {};
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    dp[1] = 0;
    pq.push({0,1});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (d[now.S] != now.F) {
            continue;
        }
        for (auto &i : g[now.S]) {
            if (d[i.F] > now.F + i.S) {
                d[i.F] = now.F + i.S;
                pq.push({d[i.F],i.F});
                dp[i.F] = dp[now.S] + 1;
            }
            else if (d[i.F] == now.F + i.S) {
                dp[i.F] = max(dp[now.S] + 1, dp[i.F]);
            }
        }
    }
    return dp[n];
}
void solve() {
    int m;
    cin >> n >> m;
    f(m) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y,z});
    }
    cout << s1() << ' '<<s2() <<' '<<s3() <<' '<<s4() << '\n';
}
int main() {
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