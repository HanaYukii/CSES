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
int n;
int v[maxn];
int pos[maxn];
void c0() {
    f1(n) {
        if (v[i] != i) {
            return;
        }
    }
    cout << 0 << '\n';
    exit(0);
}
void c1() {
    set<pair<int,int>>ans;
    f1(n) {
        if (v[i] == i) {
            continue;
        }
        if (pos[i] != v[i]) {
            return;
        }
        ans.insert({min(i,v[i]),max(i,v[i])});
    }
    cout << 1 << '\n';
    cout << ans.size() << '\n';
    for (auto &i : ans) {
        cout << i.F << ' ' << i.S << '\n';
    }
}
void c2() {
    int u[n + 5] = {};
    cout << 2 << '\n';
    vector<pair<int,int>>ans;
    f1(n) {
        if (v[i] == i) {
            continue;
        }
        int cur = i;
        while(1) {
            int p = pos[cur];
            if (pos[cur] == v[cur]) {
                break;
            }
            if (u[pos[cur]] || u[v[cur]]) {
                break;
            }
            ans.pb({pos[cur], v[cur]});
            u[pos[cur]] = u[v[cur]] = 1;
            int nxt = pos[cur];
            swap(v[ans.back().F], v[ans.back().S]);
            pos[v[ans.back().F]] = ans.back().F;
            pos[v[ans.back().S]] = ans.back().S;
            cur = nxt;
        }
    }
    cout << ans.size() << '\n';
    for (auto &i : ans) {
        cout << i.F << ' ' << i.S << '\n';
    }
    ans.clear();
    f1(n) {
        if (v[i] > i) {
            ans.pb({v[i], i});
        }
    }
    cout << ans.size() << '\n';
    for (auto &i : ans) {
        cout << i.F << ' ' << i.S << '\n';
    }
}
void solve() {
    cin >> n;
    f1(n) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    c0();
    c1();
    c2();
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