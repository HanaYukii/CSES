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
 
void solve() {
    int n;
    cin >> n;
    set<pair<int,int>>st;
    int ans[n];
    vector<pair<pair<int,int>,int>>v;
    f(n) {
        int x, y;
        cin >> x >> y;
        v.pb({{x,y},i});
    }
    sort(all(v));
    for (auto &j : v) {
        int x = j.F.F;
        int y = j.F.S;
        int i = j.S;
        if (st.lower_bound({x,0}) == st.begin()) {
            ans[i] = st.size() + 1;
            st.insert({y, ans[i]});
        }
        else {
            ans[i] = (*prev(st.lower_bound({x,0}))).S;
            st.erase(prev(st.lower_bound({x,0})));
            st.insert({y, ans[i]});
        }
    }
    cout << st.size() << '\n';
    f(n) {
        cout << ans[i] << ' ';
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