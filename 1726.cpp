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
 
void solve() {
    int k;
    cin >> k;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    double prob[8][8];
    f(8) {
        fr(j,0,8) {
            prob[i][j] = 1;
        }
    }
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            double dp[8][8] = {};
            dp[i][j] = 1;
            fr(z, 0, k) {
                double nxt[8][8] = {};
                fr(x,0,8) {
                    fr(y,0,8) {
                        double c = 0;
                        fr(m,0,4) {
                            int nx = x + dx[m];
                            int ny = y + dy[m];
                            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) {
 
                            }
                            else {
                                c += 1;
                            }
                        }
                        fr(m,0,4) {
                            int nx = x + dx[m];
                            int ny = y + dy[m];
                            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) {
 
                            }
                            else {
                                nxt[nx][ny] += dp[x][y] / c;
                            }
                        }
                    }
                }
                fr(x,0,8) {
                    fr(y,0,8) {
                        dp[x][y] = nxt[x][y];
                    }
                }
 
            } 
            fr(x,0,8) {
                fr(y,0,8) {
                    prob[x][y] *= (1.0 - dp[x][y]);
                }
            }
        }
    }
    double ans = 0;
    fr(x,0,8) {
        fr(y,0,8) {
            ans += prob[x][y];
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';
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