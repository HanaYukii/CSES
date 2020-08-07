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
 
int ans[1000005];
void solve() {
    int a;
    cin >> a;
    cout << ans[a] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 1;
    int t;
    for (int i = 1 ; i <= 1000000 ; i++) {
        for (int j = i ; j <= 1000000 ; j += i) {
            ans[j]++;
        }
    }
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
