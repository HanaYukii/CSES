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
    string s;
    cin >> s;
    int cnt[26] = {};
    for (auto &i : s) {
        cnt[i - 'A']++;
    }
    int ss = 0;
    char c = '0';
    string ans;
    f (26) {
        if (cnt[i] % 2) {
            ss++;
            c = 'A' + i;
        }
        fr (j, 0, cnt[i] / 2) {
            ans += 'A' + i;
        }
    }
    if (ss > 1) {
        cout << "NO SOLUTION\n";
        return;
    }
    cout << ans;
    if (c != '0') {
        cout << c ;
    }
    reverse(all(ans));
    cout << ans << '\n';
 
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