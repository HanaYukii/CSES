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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>>v;
    f(n) {
        int x;
        cin >> x;
        v.pb({x,i + 1});
    }
    sort(all(v));
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            int l = j + 1, r = n - 1;
            ll tar = m - v[i].F - v[j].F;
            while (r > l) {
                if (v[l].F + v[r].F > tar) {
                    r--;
                }
                else if (v[l].F + v[r].F < tar) {
                    l++;
                }
                else {
                    cout << v[i].S <<' '<<v[l].S<<' '<<v[r].S<<' '<<v[j].S<<endl;
                    exit(0);
                }
            }
        }
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
    cout << "IMPOSSIBLE\n";
}
