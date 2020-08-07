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
/*ll mi[1048576];
void build(int x, int l, int r) {
    if (l == r) {
        cin >> mi[x];
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1, l, mid);
    build(x<<1|1, mid + 1, r);
}
void pushdown(int x) {
    if (!mi[x]) return;
    mi[x<<1] += mi[x];
    mi[x<<1|1] += mi[x];
    mi[x] = 0;
}
ll query(int x, int l, int r, int pos) {
    if (l == r) {
        return mi[x];
    }
    int mid = (l + r) >> 1;
    pushdown(x);
    if (pos <= mid) {
        return query(x<<1,l,mid,pos);
    }
    else {
        return query(x<<1|1,mid+1,r,pos);
    }
}
void update(int x, int l, int r, int ql, int qr, int v) {
    if (ql <= l &&  qr >= r) {
        mi[x] += v;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(x);
    if (ql <= mid) {
        update(x<<1,l,mid,ql,qr,v);
    }
    if (qr > mid){
        update(x<<1|1,mid+1,r,ql,qr,v);
    }
    
}*/
void solve() {
    int n, m;
    cin >> n >> m;
    int pre[n + 5][n + 5] = {};
    f1(n) {
        string s;
        cin >> s;
        s = " " + s;
        fr(j,1,n+1) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            pre[i][j] += (s[j] == '*');
        }
    }
    while (m--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << '\n';
    }
    /*build(1,1,n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;;
            update(1,1,n,l,r,x);
        }
        else {
            int x;
            cin >> x;
            cout << query(1,1,n,x) << '\n';
        }
    }*/
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}