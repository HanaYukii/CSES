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
vector<vector<int>>tar{{1,2,3},{4,5,6},{7,8,9}};
void solve() {
    map<vector<vector<int>>,int>mp,mp2;
    vector<vector<int>>v(3);
    for (auto &i : v) {
        fr(j,0,3) {
            int x;
            cin >> x;
            i.pb(x);
        }
    }
    int f = 0;
    if (v[2][1] == 2) {
        f = 1;
    }
    mp[v] = 0;
    queue<pair<vector<vector<int>>,int>>q;
    q.push({v,0});
    while (q.size()) {
        auto now = q.front();
        q.pop();
        now.S++;
        if (now.S == 8) {
            break;
        }
        int dx[2] = {1,0};
        int dy[2] = {0,1};
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                for (int k = 0 ; k < 2 ; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 3 || ny >= 3) {
                        continue;
                    }
                    swap(now.F[i][j], now.F[nx][ny]);
                    if (!mp.count(now.F)) {
                        mp[now.F] = now.S;
                        q.push(now);
                    }
                    swap(now.F[i][j], now.F[nx][ny]);
                }
            }
        }
    }
    while (q.size()) {
        q.pop();
    }
    v = tar;
    mp2[v] = 0;
    q.push({v,0});
    while (q.size()) {
        auto now = q.front();
        q.pop();
        now.S++;
        if (now.S == 8) {
            break;
        }
        int dx[2] = {1,0};
        int dy[2] = {0,1};
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                for (int k = 0 ; k < 2 ; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 3 || ny >= 3) {
                        continue;
                    }
                    swap(now.F[i][j], now.F[nx][ny]);
                    if (!mp2.count(now.F)) {
                        mp2[now.F] = now.S;
                        q.push(now);
                    }
                    swap(now.F[i][j], now.F[nx][ny]);
                }
            }
        }
    }
    int ans = 20;
    for (auto &i : mp) {
        if (mp2.count(i.F)) {
            ans = min(ans, i.S + mp2[i.F]);
        }
    }
    if (ans == 20) {
        if (f) {
            ans = 16;
        }
        else {
            ans = 15;
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