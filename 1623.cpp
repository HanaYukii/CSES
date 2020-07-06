#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define pll pair<ll,ll>
#define pii pair<int,int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll>v;
    f(n) {
        ll x;
        cin >> x;
        sum += x;
        v.pb(x);
    }
    ll mi = sum;
    f(1<<n) {
        ll s = 0;
        ll s2 = 0;
        fr(j, 0, n) {
            if (i & (1<<j)) {
                s += v[j];
            }
            else {
                s2 += v[j];
            }
        }
        mi = min(mi, abs(s - s2));
    }
    cout << mi << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t= 1;
    while (t--) {
        solve();
    }
}