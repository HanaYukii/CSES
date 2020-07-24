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
ll sum[maxn<<2];
ll tg[maxn<<2];
ll tgc[maxn<<2];
void pushup(int x) {
    sum[x] = sum[x<<1] + sum[x<<1|1];
}
void pushdown(int x,int l, int r) {
    if (!tgc[x]) {
        return;
    }
    int mid = (l + r) >> 1;
    sum[x<<1] += (tg[x] + tg[x] + (mid - l)*tgc[x]) * (mid - l + 1) / 2;
    tg[x<<1] += tg[x];
    tgc[x<<1]+=tgc[x];
    sum[x<<1|1] += (tg[x] + tg[x] + (mid + 1 - l + r - l)*tgc[x]) * (r - mid) / 2;
    tg[x<<1|1] += tg[x] + (mid + 1 - l) * tgc[x];
    tgc[x<<1|1]+=tgc[x];
    tg[x] = 0;
    tgc[x] = 0;
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
void update(int x, int l, int r, int ql, int qr, ll del) {
    if (ql <= l && qr >= r) {
        tg[x] += del;
        tgc[x]++;
        sum[x] += (del + del + r - l) * (r - l + 1) / 2;
        return;
    }
    pushdown(x,l,r);
    int mid = (l + r) >> 1;
    if (ql <= mid) {
        update(x<<1,l,mid,ql,qr,del);
        del += min((mid - ql + 1),mid-l+1);
    }
    if (qr > mid) {
        update(x<<1|1,mid+1,r,ql,qr,del);
    }
    pushup(x);
}
ll query(int x, int l, int r, int ql,int qr) {
    if (ql <= l && qr >= r) {
        return sum[x];
    }
    pushdown(x,l,r);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (ql <= mid) {
        ans += query(x<<1,l,mid,ql,qr);
    }
    if (qr > mid) {
        ans += query(x<<1|1,mid+1,r,ql,qr);
    }
    return ans;
}
void solve() {
    int n, m;
    cin >> n >> m;
    build(1,1,n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            update(1,1,n,l,r,1);
        }
        else {
            cout << query(1,1,n,l,r) << '\n';
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