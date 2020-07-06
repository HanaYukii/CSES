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
    string s;
    cin >> s;
    int now = 1;
    int mx = 1;
    f1(s.size() - 1) {
        if (s[i] == s[i - 1]) {
            now++;
        }
        else {
            now = 1;
        }
        mx = max(mx, now);
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