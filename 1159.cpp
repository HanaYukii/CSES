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
 
int n, m;
int dp[maxn];
int h[maxn], s[maxn], k[maxn];
void update(int x) {
    for (int i = 0 ; i < s[x] ; i++) {
        if (i >= m) {
            break;
        }
        vector<pair<int,int>>v;
        int del = 0;
        for (int j = i ; j <= m ; j += s[x]) {
            v.pb({dp[j] - del,j});
            del += h[x];
        }
        deque<int>dq;
        dq.push_back(0);
        vector<int>t;
        t.pb(dp[v[0].S]);
        for (int j = 1 ; j < v.size() ; j++) {
            if (dq.front() < j - k[x]) {
                dq.pop_front();
            }
            int idx = v[dq.front()].S;
            t.pb(max(dp[v[j].S], dp[idx] + h[x] * (j - dq.front())));
            while(dq.size() && v[j].F >= v[dq.back()].F) {
                dq.pop_back();
            }
            dq.push_back(j);
        }
        for (int j = 1 ; j < v.size() ; j++) {
            dp[v[j].S] = t[j];
        }
    }
}
void solve() {
    cin >> n >> m;
    f (n) {
        cin >> s[i];
    }
    f (n) {
        cin >> h[i];
    }
    f (n) {
        cin >> k[i];
    }
    f (n) {
        update(i);
    }
    cout << dp[m] << '\n';
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