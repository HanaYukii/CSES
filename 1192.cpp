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
 
void solve() {
    int n, m;
    cin >> n >> m;
    string s[n];
    f (n) {
        cin >> s[i];
    }
    queue<pair<int,int>>q;
    int ans = 0;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    f(n) {
        fr(j,0,m) {
            if (s[i][j] != '.') {
                continue;
            }
            ans++;
            q.push({i,j});
            s[i][j] = '#';
            while (q.size()) {
                auto now = q.front();
                q.pop();
                fr(k,0,4) {
                    int nx = now.F + dx[k];
                    int ny = now.S + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '#') {
                        continue;
                    } 
                    s[nx][ny] = '#';
                    q.push({nx,ny});
                }
            }
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