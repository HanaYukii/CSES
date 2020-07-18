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
 
void solve() {
    int n, m;
    cin >> n >> m;
    string s[n];
    f (n) {
        cin >> s[i];
    }
    int fr[n][m];
    int d[n][m];
    int dm[n][m];
    memset(fr, -1, sizeof(fr));
    memset(d,-1,sizeof(d));
    memset(dm,-1,sizeof(dm));
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    string tar = "DURL";
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (s[i][j] == 'A') {
                d[i][j] = 0;
                queue<pair<int,int>>q;
                q.push({i,j});
                while (!q.empty()) {
                    auto now = q.front();
                    q.pop();
                    for (int k = 0 ; k < 4 ; k++) {
                        int nx = now.F + dx[k];
                        int ny = now.S + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || ~d[nx][ny] ||s[nx][ny] == '#') {
                            continue;
                        }
                        d[nx][ny] = d[now.F][now.S] + 1;
                        fr[nx][ny] = k;
                        q.push({nx,ny});
                    }
                }             
            }
        }
    }
    queue<pair<int,int>>q;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (s[i][j] == 'M') {
                dm[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (int k = 0 ; k < 4 ; k++) {
            int nx = now.F + dx[k];
            int ny = now.S + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || ~dm[nx][ny] ||s[nx][ny] == '#') {
                continue;
            }
            dm[nx][ny] = dm[now.F][now.S] + 1;
            q.push({nx,ny});
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (d[i][j] >= dm[i][j] && ~dm[i][j]) {
                    continue;
                }
                if (d[i][j] == -1) {
                    continue;
                }
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
                
                return;
            }
            
        }
    }
    cout << "NO\n";
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
