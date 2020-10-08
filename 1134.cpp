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
 
void solve() {
    int n;
    cin >> n;
    int cnt[n + 5] = {};
    vector<int>v;
    set<int>na;
    f1(n - 2) {
        int x;
        cin >> x;
        v.pb(x);
        cnt[x]++;
    }
    f1(n) {
        if (!cnt[i]) {
            na.insert(i);
        }
    }
    for (auto &i : v) {
        cout << *na.begin() << ' ' << i << '\n';
        cnt[i]--;
        na.erase(na.begin());
        if (!cnt[i]) {
            na.insert(i);
        }
    }
    cout << *na.begin() <<' '<<*na.rbegin() << '\n';
}
int main() {
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