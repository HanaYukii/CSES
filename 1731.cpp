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
const int maxn = 1e6+5;
string t,s[maxn];
int n;
ll dp[5005];
struct 
{
    int c[maxn][26], d[maxn][26], sl[maxn], ol[maxn], de[maxn], m = 1;
    void ins(string &s) {
        int u = 0;
        for (auto &i : s) {
            if (!c[u][i - 'a']) {
                c[u][i - 'a'] = m++;
            }
            u = c[u][i - 'a'];
        }
        ol[u] = u;
    }
    void ac() {
        queue<int>q;
        q.push(0);
        while (q.size()) {
            auto u = q.front();
            q.pop();
            for (int i = 0 ; i < 26 ; i++) {
                if (c[u][i]) {
                    int v = c[u][i];
                    de[v] = de[u] + 1;
                    sl[v] = d[sl[u]][i];
                    if (!ol[v]) {
                        ol[v] = ol[sl[v]];
                    }
                    d[u][i] = v;
                    q.push(v);
                }
                else {
                    d[u][i] = d[sl[u]][i];
                }
            }
        }
    } 
}ac;
void solve() {
    int k;
    cin >> t >> k;
    n = t.size();
    dp[0] = 1;
    f(k) {
        cin >> s[i];
        ac.ins(s[i]);
    }
    ac.ac();
    int u = 0;
    for (int i = 1 ; i <= n ; i++) {
        u = ac.d[u][t[i - 1] - 'a'];
        int v = ac.ol[u];
        while (v) {
            dp[i] = (dp[i] + dp[i - ac.de[v]]) % mod;
            v = ac.ol[ac.sl[v]];
        }
    }
    cout << dp[n] << '\n';
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