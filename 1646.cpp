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
int mi[1048576];
void build(int x, int l, int r) {
    if (l == r) {
        cin >> mi[x];
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1, l, mid);
    build(x<<1|1, mid + 1, r);
    mi[x] = min(mi[x<<1], mi[x<<1|1]);
}
int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        return mi[x];
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return query(x<<1,l,mid,ql,qr);
    }
    else if(ql > mid) {
        return query(x<<1|1,mid+1,r,ql,qr);
    }
    else {
        return min(query(x<<1,l,mid,ql,qr), query(x<<1|1,mid+1,r,ql,qr));
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    build(1,1,n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << query(1,1,n,l,r) << '\n';
    }
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