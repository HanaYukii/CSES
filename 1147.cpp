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
const int maxn = 2e5+5;
 
void solve() {
    int n, m;
    cin >> n >> m;
    int dp[n + 5][m + 5] = {};
    int ans = 0;
    f1(n) {
        string s;
        cin >> s;
        s = " "+ s;
        fr(j,1,m+1) {
            if (s[j] == '.') {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            else {
                dp[i][j] = 0;
            }
        }
        dp[i][0] = -2;
        dp[i][m+1] = -1;
        int l[m + 5];
        stack<int>st;
        st.push(0);
        fr(j,1,m+2) {
            while (dp[i][st.top()] >= dp[i][j]) {
                ans = max(ans,(j - l[st.top()] - 1) * dp[i][st.top()]);
                st.pop();
            }
            l[j] = st.top();
            st.push(j);
        }
    }
    cout << ans << '\n';
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