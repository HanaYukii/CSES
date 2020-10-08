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
vector<pair<int,int>>ans;
void solve() {
    int n;
    cin >> n;
    set<pair<int,int>>st;
    f1(n) {
        int x;
        cin >> x;
        if (x)
            st.insert({x,i});
    }
    while(st.size()) {
        auto x = *st.rbegin();
        st.erase(--st.end());
        if (st.size() < x.first) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        vector<pair<int,int>>add;
        f(x.first) {
            auto nxt = *st.rbegin();
            st.erase(--st.end());
            ans.pb({nxt.S,x.S});
            nxt.F--;
            if (nxt.F) {
                add.push_back(nxt);
            }
        }
        for (auto &i : add) {
            st.insert(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto &i : ans) {
        cout << i.F << ' ' << i.S << '\n';
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