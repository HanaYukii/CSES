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
    map<int,int>mp;
    f(n) {
        int x, y;
        cin >> x >> y;
        mp[x]++;
        mp[y]--;
    }
    int mx = 0;
    int cur = 0;
    for (auto &i : mp) {
        cur += i.S;
        mx = max(mx, cur);
    }
    cout << mx << '\n';
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