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
string sss;
struct ss
{
    ss() {
        ls = rs = mx = 0;
    }
    int ls,rs,mx;
};
ss s[maxn][2];
void pushup(int x, int l, int r,int tp) {
    int mid = (l + r) >> 1;
    if (s[x<<1][tp].ls == mid - l + 1) {
        s[x][tp].ls = s[x<<1][tp].ls + s[x<<1|1][tp].ls;
    }
    else {
        s[x][tp].ls = s[x<<1][tp].ls;
    }
    if (s[x<<1|1][tp].rs == r - mid) {
        s[x][tp].rs = s[x<<1][tp].rs + s[x<<1|1][tp].rs;
    }
    else {
        s[x][tp].rs = s[x<<1|1][tp].rs;
    }
 
    s[x][tp].mx = max({s[x<<1][tp].mx,s[x<<1|1][tp].mx,s[x<<1][tp].rs + s[x<<1|1][tp].ls});
}
void build(int x, int l, int r) {
    if (l == r) {
        if (sss[l] == '1') {
            s[x][1].ls = s[x][1].rs = s[x][1].mx = 1;
        }
        else {
            s[x][0].ls = s[x][0].rs = s[x][0].mx = 1;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x,l,r,0);
    pushup(x,l,r,1);
}
void update(int x,int l,int r, int p) {
    if (l == r) {
        if (sss[l] == '0') {
            s[x][1].ls = s[x][1].rs = s[x][1].mx = 1;
            s[x][0].ls = s[x][0].rs = s[x][0].mx = 0;
            sss[l] = '1';
        }
        else {
            s[x][1].ls = s[x][1].rs = s[x][1].mx = 0;
            s[x][0].ls = s[x][0].rs = s[x][0].mx = 1;
            sss[l] = '0';
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) {
        update(x<<1,l,mid,p);
    }
    else {
        update(x<<1|1,mid+1,r,p);
    }
    pushup(x,l,r,0);
    pushup(x,l,r,1);
}
void solve() {
    cin >> sss;
    int n = sss.size();
    sss = " " + sss;
    build(1,1,n);
    int k;
    cin >> k;
    f(k) {
        int x;
        cin >> x;
        update(1,1,n,x);
        cout << max(s[1][0].mx, s[1][1].mx) <<' ';
    }
    cout << '\n';
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