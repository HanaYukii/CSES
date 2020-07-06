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
    int n, m, k;
    cin >> n >> m >> k;
    queue<ll>q;
    vector<ll>v1;
    vector<int>v2;
    for (int i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        v1.pb(x - k);
    }
    sort(all(v1));
    for (int i = 0 ; i < m ; i++) {
        int x;
        cin >> x;
        v2.pb(x);
    }
    sort(all(v2));
    int ptr = 0;
    k <<= 1;
    int ans = 0;
    for (int i = 0 ; i < m ; i++) {
        while (ptr < n && v1[ptr] <= v2[i]) {
            q.push(v1[ptr++] + k);
        }
        while (q.size() && q.front() < v2[i]) {
            q.pop();
        }
        if (q.size()) {
            ans++;
            q.pop();
        }
    }
    cout << ans << '\n';
 
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