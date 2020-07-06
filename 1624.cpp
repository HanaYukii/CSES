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
int ans = 0;
string s[8];
int h[8];
int v[8];
int d1[15];
int d2[15];
void dfs(int now, int cur) {
    int x = now / 8;
    int y = now % 8;
    if (cur == 8){
        ans++;
        return;
    }
    if (now == 64) {
        return ;
    }
    if (s[x][y] == '*') {
        dfs(now + 1, cur);
    }
    else {
        if (!v[x] && !h[y] && !d1[x+y] && !d2[x-y+7]) {
            v[x] = h[y] = d1[x+y] = d2[x-y+7] = 1;
            dfs(now + 1, cur + 1); 
            v[x] = h[y] = d1[x+y] = d2[x-y+7] = 0;
        }
        dfs(now + 1, cur);
    }
}
void solve() {
    f(8) {
        cin >> s[i];
    }
    dfs(0,0);
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