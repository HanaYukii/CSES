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
    int fr[n][m];
    memset(fr, -1, sizeof(fr));
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    string tar = "DURL";
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (s[i][j] == 'A') {
                queue<pair<int,int>>q;
                q.push({i,j});
                while (!q.empty()) {
                    auto now = q.front();
                    q.pop();
 
                    if (s[now.F][now.S] == 'B') {
                        break;
                    }
                    for (int k = 0 ; k < 4 ; k++) {
                        int nx = now.F + dx[k];
                        int ny = now.S + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || ~fr[nx][ny] ||s[nx][ny] == '#' || s[nx][ny] == 'A') {
                            continue;
                        }
                        fr[nx][ny] = k;
                        q.push({nx,ny});
                    }
                }             
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (s[i][j] == 'B') {
                if (fr[i][j] == -1) {
                    cout << "NO\n";
                }
                else {
                    int nx = i, ny = j;
                    string ans;
                    while (~fr[nx][ny]) {
                        ans += tar[fr[nx][ny]];
                        int x = fr[nx][ny];
                        nx -= dx[x];
                        ny -= dy[x];
                    }
                    reverse(all(ans));
                    cout << "YES\n";
                    cout << ans.size() << '\n';
                    cout << ans << '\n';
                }
                return;
            }
            
        }
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