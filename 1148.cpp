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
short dp[1005][1005] = {};
int ans[1005][1005] = {};
void solve() {
    int n, m;
    scanf("%d %d",&n,&m);
    f1(n) {
        char s[m + 1];
        scanf("%s",s+1);
        fr(j,1,m+1) {
            if (s[j] == '.') {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            else {
                dp[i][j] = 0;
            }
        }
        dp[i][0] = -2;
        vector<int>st;
        st.push_back(0);
        fr(j,1,m+2) {
            while (dp[i][st.back()] >= dp[i][j]) {
                ans[dp[i][st.back()]][j-st.back()+1]--;
                ans[dp[i][st.back()]][j-st[st.size()-2]+1]++;
                st.pop_back();
            }
            st.push_back(j);
            /*for (int z = (int)st.size() -2 ; z >= 0; z--) {
                ans[dp[i][st[z+1]]][j-st[z+1]+1]++;
                ans[dp[i][st[z+1]]][j-st[z]+1]--;
            }*/
            ans[dp[i][st.back()]][j-st[st.size()-2]+1]--;
            ans[dp[i][st.back()]][1]++;
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            ans[i][j] += ans[i][j-1];
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            ans[i][j] += ans[i][j-1];
        }
    }
    for (int i = n - 1 ; i >= 1 ; i--) {
        for (int j = m ; j >= 1 ; j--) {
            ans[i][j] += ans[i + 1][j];
        }
    }
    f1(n) {
        fr(j,1,m+1) {
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
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