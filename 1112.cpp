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
vector<int> build(string &t) {
  vector<int> F(t.size()); F[0] = -1;
  for (int i = 1, pos = -1 ; i < t.size() ; i++) {
    while (~pos && t[i] != t[pos + 1]) pos = F[pos];
    if (t[i] == t[pos + 1]) pos++; F[i] = pos;
  }
  return F;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>fail = build(s);
    ll dp[n + 1][s.size()+1] = {};
    dp[0][0] = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < s.size() ; j++) {
            dp[i + 1][j + 1] += dp[i][j];
            dp[i + 1][j + 1] %= mod;
            for (char c = 'A' ; c <= 'Z' ; c++) {
                if (c == s[j]) continue;
                int pos = j - 1;
                while (~pos && c != s[pos + 1]) {
                    pos = fail[pos];
                }
                if (c == s[pos + 1])
                    pos++;
                dp[i + 1][pos + 1] += dp[i][j];
                dp[i + 1][pos + 1] %= mod;
            }
        }
    }
    ll tar = 1;
    f(n) {
        tar *= 26;
        tar %= mod;
    }
    f(s.size()) {
        tar -= dp[n][i];
        tar += mod;
        tar %= mod;
    }
    cout << tar << '\n';
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