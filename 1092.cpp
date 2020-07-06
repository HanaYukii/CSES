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
int v[200005];
void solve() {
    ll n;
    cin >> n;
    if ((n * (n + 1) / 2) % 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int>v[2];
    ll rem = (n * (n + 1) / 2) / 2;
    for (int i = n ; i >= 1 ; i--) {
        if (rem >= i) {
            v[0].pb(i);
            rem -= i;
        }
        else {
            v[1].pb(i);
        }
    }
    for (int i = 0 ; i < 2 ; i++) {
        cout << v[i].size() << '\n';
        for (auto &j : v[i]) {
            cout << j <<' ';
        }
        cout << '\n';
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