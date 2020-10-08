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
const int maxn = 2000005;
vector<int>fail;
void build(string s) {
    fail.pb(-1);
    int p1 = 0, p2 = -1;
    while (p1 < (int)s.size()) {
        if (p2 == -1 || s[p1] == s[p2]) {
            p1++, p2++;
            fail.pb(p2);
        }
        else {
            p2 = fail[p2];
        }
    }
}
int match(string s, string t) {
    int p1 = 0, p2 = 0;
    int ans = 0;
    while (p1 < (int)s.size()) {
        if (p2 == -1 || s[p1] == t[p2]) {
            p1++, p2++;
            if (p2 == (int)t.size()) {
                ans++;
                p2 = fail[p2];
            }
        }
        else {
            p2 = fail[p2];
        }
    }
    return ans;
}
void solve() {
    string t;
    cin >> t;
    build(t);
    vector<int>ans;
    int cur = t.size();
    while (~fail[cur] != -1) {
        ans.pb(fail[cur]);
        cur = fail[cur];
    }
    reverse(all(ans));
    for (auto &i : ans) {
        cout << i << ' ';
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