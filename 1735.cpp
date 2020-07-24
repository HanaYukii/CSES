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
ll sum[maxn << 2];
ll lzd[maxn << 2];
ll lzc[maxn << 2];
void pushup(int x) {
    sum[x] = sum[x<<1] + sum[x<<1|1];
}
void pushdown(int x, int l, int r) {
    int mid = (l + r) >> 1;
    if (lzc[x]) {
        lzc[x<<1] = lzc[x<<1|1] = lzc[x];
        lzc[x] = 0;
        lzd[x<<1] = lzd[x<<1|1] = 0;
        sum[x<<1] = (mid - l + 1) * lzc[x<<1];
        sum[x<<1|1] = (r - mid) * lzc[x<<1|1];
    }
    if (lzd[x]) {
        lzd[x<<1] += lzd[x];
        lzd[x<<1|1] += lzd[x];
        sum[x<<1] += lzd[x] * (mid - l + 1);
        sum[x<<1|1] += lzd[x] * (r - mid);
        lzd[x] = 0;
    }
}
void build(int x, int l, int r) {
    if (l == r) {
        cin >> sum[x];
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x, int l, int r, int ql, int qr, ll v) {
    if (ql <= l && qr >= r) {
        lzd[x] += v;
        sum[x] += v * (r - l + 1);
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(x,l,r);
    if (ql <= mid) {
        update(x<<1,l,mid,ql,qr,v);
    }
    if (qr > mid) {
        update(x<<1|1,mid+1,r,ql,qr,v);
    }
    pushup(x);
} 
void update2(int x, int l, int r, int ql, int qr, ll v) {
    if (ql <= l && qr >= r) {
        lzc[x] = v;
        lzd[x] = 0;
        sum[x] = v * (r - l + 1);
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(x,l,r);
    if (ql <= mid) {
        update2(x<<1,l,mid,ql,qr,v);
    }
    if (qr > mid) {
        update2(x<<1|1,mid+1,r,ql,qr,v);
    }
    pushup(x);
} 
ll query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        return sum[x];
    }
    int mid = (l + r) >> 1;
    ll ret = 0;
    pushdown(x,l,r);
    if (ql <= mid) {
        ret += query(x<<1,l,mid,ql,qr);
    }
    if (qr > mid) {
        ret += query(x<<1|1,mid+1,r,ql,qr);
    }
    pushup(x);
    return ret;
}
void solve() {
    int n, m;
    cin >> n >> m;
    build(1,1,n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, d;
            cin >> l >> r >> d;
            update(1,1,n,l,r,d);
        }
        else if (op == 2) {
            int l, r, c;
            cin >> l >> r >> c;
            update2(1,1,n,l,r,c);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1,1,n,l, r) << '\n';
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