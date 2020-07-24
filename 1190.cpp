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
 
ll mx[1048576];
ll mxl[1048576];
ll mxr[1048576];
ll sum[1048576];
void pushup(int x) {
    sum[x] = sum[x<<1] + sum[x<<1|1];
    mxl[x] = max(mxl[x<<1],sum[x<<1] + mxl[x<<1|1]);
    mxr[x] = max(mxr[x<<1|1], sum[x<<1|1] + mxr[x<<1]);
    mx[x] = max({mx[x<<1],mx[x<<1|1],mxl[x<<1|1] + mxr[x<<1]});
}
void build(int x, int l, int r) {
    if (l == r) {
        cin >> mx[x];
        mxl[x] = max(0LL,mx[x]);
        mxr[x] = max(0LL,mx[x]);
        sum[x] = mx[x];
    }
    else {
        int mid = (l + r) >> 1;
        build(x<<1, l, mid);
        build(x<<1|1,mid+1,r);
        pushup(x);
    }
}
void update(int x, int l, int r, int pos, int v) {
    if (l == r) {
        mx[x] = v;
        mxl[x] = max(0LL,mx[x]);
        mxr[x] = max(0LL,mx[x]);
        sum[x] = mx[x];
    }
    else {
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            update(x<<1, l, mid, pos, v);
        }
        else {
            update(x<<1|1,mid+1,r,pos,v);
        }
        pushup(x);
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    build(1,1,n);
    f(m) {
        int x, v;
        cin >> x >> v;
        update(1,1,n,x,v);
        cout << mx[1] << '\n';
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