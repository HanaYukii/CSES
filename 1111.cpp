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
const int maxn = 2000005;
vector<char>v;
string manacher(string ss) {
    v.pb('*');
    for (auto &i : ss) {
        v.pb('#');
        v.pb(i);
    }
    v.pb('#');
    int dp[v.size()] = {};
    int mx = 0, id = 0;
    for (int i = 0 ; i < v.size() ; i++) {
        dp[i] = mx > i ? min(dp[2*id-i], mx - i) : 1;
        while(v[i + dp[i]] == v[i - dp[i]]) {
            dp[i]++;
        }
        if (i + dp[i] > mx) {
            id = i;
            mx = i + dp[i];
        }
    }
    int ans = 0;
    for (int i = 0 ; i < v.size() ; i++) {
        if (dp[i] > dp[ans]) {
            ans = i;
        }
    }
    string ret;
    for (int i = ans - dp[ans] + 1 ; i < ans + dp[ans] ; i++) {
        if (v[i] >= 'a' && v[i] <= 'z') {
            ret += v[i];
        }
    }
    return ret;
}
void solve() {
    string s;
    cin >> s;
    cout << manacher(s) << '\n';
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