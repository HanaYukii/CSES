#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
struct s{
    int x;
    int l,r,del;
};
bool cmp(s x,s y){
    return x.x < y.x;
}
int sum[8000005];
void pushup(int x) {
    sum[x] = sum[x<<1] + sum[x<<1|1];
}
void update(int x, int l, int r, int p, int d) {
    if (l == r) {
        sum[x] += d;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) {
        update(x<<1,l,mid,p,d);
    }
    else {
        update(x<<1|1,mid+1,r,p,d);
    }
    pushup(x);
}
int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        return sum[x];
    }
    int mid = (l + r) >> 1;
    int sum = 0;
    if (ql <= mid) {
        sum += query(x<<1,l,mid,ql,qr);
    }
    if (qr > mid) {
        sum += query(x<<1|1,mid+1,r,ql,qr);
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<s>v;
    vector<s>q;
    ll ans = 0;
    f(n){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) {
            v.pb({x1,y1,y2,1});
            v.pb({x2+1,y1,y2,-1});
        }
        else {
            q.pb({x1,y1,y2,0});
        }
    }
    sort(v.begin(),v.end(),cmp);
    sort(q.begin(),q.end(),cmp);
    int ptr = 0;
    for(auto i:q){
        while (ptr < v.size() && v[ptr].x <= i.x) {
            update(1,-1000000,1000000,v[ptr].l,v[ptr].del);
            ptr++;
        }
        ans += query(1,-1000000,1000000,i.l,i.r);
    }
    cout << ans << endl;
}