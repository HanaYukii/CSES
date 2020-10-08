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
const int mod = 998244353;
const int maxn = 100010;
int n;
vector<ll>disx, disy;
vector<vector<ll>>q;
vector<pair<pair<ll,ll>,pair<ll,ll>>>line;
int dx[maxn],dy[maxn], d[maxn],sz[maxn];
int b[maxn<<1];
void update(int x,int d) {
    x+=5;
    while (x < maxn * 2) {
        b[x] += d;
        x += x & (-x);
    }
}
int query(int x) {
    int ret = 0;
    x += 5;
    while (x) {
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
int query(int l,int r) {
    return query(r) - query(l - 1);
}
void go() {
    cin >> n;
    ll sum = 0;
    
    ll x = 0, y = 0;
    f(n) {
        char c;
        cin >> c >> d[i];
        if (c == 'R') {
            dx[i]++;
        }
        else if (c == 'L') {
            dx[i]--;
        }
        else if (c == 'U') {
            dy[i]--;
        }
        else {
            dy[i]++;
        }
        if (i && ((dx[i] * dx[i - 1] == -1)||(dy[i] * dy[i-1] == -1))) {
            n = i;
            break;
        }
        sum += d[i];
        ll nx = x + dx[i] * (d[i] - 1);
        ll ny = y + dy[i] * (d[i] - 1);
        line.pb({{min(nx,x),min(ny,y)},{max(nx,x),max(ny,y)}});
        disx.pb(line.back().F.F);
        disx.pb(line.back().S.F);
        disy.pb(line.back().F.S);
        disy.pb(line.back().S.S);
        if (dy[i]) {
            q.pb({line.back().F.F,0,line.back().F.S,line.back().S.S});
        }
        else {
            q.pb({line.back().S.F,1,line.back().F.S});
            q.pb({line.back().F.F,-1,line.back().F.S});
        }
        sz[i + 1] = q.size();
        x = nx+ dx[i], y = ny + dy[i];
    }
    sort(all(disx));
    disx.erase(unique(all(disx)),disx.end());
    sort(all(disy));
    disy.erase(unique(all(disy)),disy.end());
    for (auto &i:q) {
        if(i.size() == 3) {
            i[0] = lower_bound(all(disx),i[0]) - disx.begin();
            i[2] = lower_bound(all(disy),i[2]) - disy.begin();
        }
        else {
            i[0] = lower_bound(all(disx),i[0]) - disx.begin();
            i[2] = lower_bound(all(disy),i[2]) - disy.begin();
            i[3] = lower_bound(all(disy),i[3]) - disy.begin();
        }
    }
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        vector<vector<ll>>v(q.begin(),q.begin()+sz[mid]);
        sort(all(v));
        memset(b,0,sizeof(b));
        pair<int,int>last = {-1,-1};
        int f = 0;
        for (auto &i : v) {
            if (i.size()==3){
                i[1] = -i[1];
                if (i[1] == 1 && query(i[2],i[2])) {
                    f = 1;
                }
                update(i[2],i[1]);
            }
            else {
                if (query(i[2],i[3])) {
                    f = 1;
                }
                if(i[0] == last.F && i[2] <=last.S) {
                    f = 1;
                }
                last = {i[0],i[3]};
            }
            if (f)break;
        }
        if (f) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    if (l == n) {
        cout << sum << '\n';
        return;
    }
    ll ans = 0;
    x = y = 0;
    for (int  i = 0 ; i < l ; i++) {
        ans += d[i];
        x += dx[i] * d[i];
        y += dy[i] * d[i];
    }
    int R = d[l];
    int L = 0;
    while (R - L > 1) {
        int mid = (L + R) >> 1;
        int f = 0;
        for (int i = 0 ; i < l ; i++) {
            vector<ll>v1 = {x,y,x+dx[l] * (mid-1),y+dy[l] * (mid - 1)};
            vector<ll>v2 = {line[i].F.F,line[i].F.S,line[i].S.F,line[i].S.S};
            if (v1[0]>v1[2]) {
                swap(v1[0],v1[2]);
            }
            if (v1[1]>v1[3]) {
                swap(v1[1],v1[3]);
            }
            if (max(v1[0],v2[0]) <= min(v1[2],v2[2]) && max(v1[1],v2[1]) <= min(v1[3],v2[3])) {
                f = 1;
                break;
            }
        }
        if (f) {
            R = mid;
        }
        else {
            L = mid;
        }
    }
    cout << ans + L << '\n';
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
        go();
    }
    
}