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
    int a, b;
    cin >> a >> b;
    if ((a + b) % 3) {
        cout << "NO\n";
        return;
    }
    if (a > b * 2 || b > a * 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}