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
    mi[x] = max(mi[x<<1],mi[x<<1|1]);
}
void pushdown(int x) {
    if (!mi[x]) return;
    mi[x<<1] += mi[x];
    mi[x<<1|1] += mi[x];
    mi[x] = 0;
}
int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        return mi[x];
    }
    int mid = (l + r) >> 1;
    int mx = 0;
    if (ql <= mid) {
        mx = max(mx, query(x<<1,l,mid,ql,qr));
    }
    if (qr > mid){
        mx = max(mx, query(x<<1|1,mid+1,r,ql,qr));
    }
    return mx;
}
void update(int x, int l, int r, int pos, int v) {
    if (l == r) {
        mi[x] -= v;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        update(x<<1,l,mid,pos,v);
    }
    else {
        update(x<<1|1,mid+1,r,pos,v);
    }
    mi[x] = max(mi[x<<1],mi[x<<1|1]);
}*/
int v[300005];
int b[300005];
void update(int x,int d) {
    while (x < (1<<18)) {
        b[x] += d;
        x += (x) & (-x);
    }
}
int get(int k) {
    int cur = 0;
    for (int i = 17 ; i >= 0 ; i--) {
        if (b[cur + (1<<i)] < k) {
            k -= b[cur + (1<<i)];
            cur += (1<<i);
        }
    }
    return cur + 1;
}
void solve() {
    int n;
    cin >> n;
    f1(n) {
        update(i,1);
        cin >> v[i];
    }
    f1(n) {
        int x;
        cin >> x;
        x = get(x);
        cout << v[x] <<' ';
        update(x, -1);
    }
    /*int n, m;
    cin >> n >> m;
    build(1,1,n);
    while (m--) {
        int x;
        cin >> x;
        if (query(1,1,n,1,n) < x) {
            cout << 0 <<' ';
        }
        else {
            int l = 0, r = n;
            while (r - l > 1){
                int mid = (l + r) >> 1;
                if(query(1,1,n,1,mid) < x) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            cout << r <<' ';
            update(1,1,n,r,x);
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