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
int n;
string s[1005];
int b[1005][1005];
void update(int x, int y, int d) {
    while (x <= n) {
        int ty = y;
        while (ty <= n) {
            b[x][ty] += d;
            ty += ty & (-ty);
        }
        x += x & (-x);
    }
}
int query(int x, int y) {
    int ret = 0;
    while (x) {
        int ty = y;
        while (ty) {
            ret += b[x][ty];
            ty -= ty & (-ty);
        }
        x -= x & (-x);
    }
    return ret;
}
void solve() {
    int q;
    cin >> n >> q;
    f1 (n) {
        cin >> s[i];
        s[i] = " " + s[i];
        fr (j, 1, n + 1) {
            if (s[i][j] == '*') {
                update(i, j, 1);
            }
        }
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            if (s[x][y] == '*') {
                s[x][y] = '.';
                update(x, y, -1);
            }
            else {
                s[x][y] = '*';
                update(x, y, 1);
            }
        }
        else {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1) << '\n';
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