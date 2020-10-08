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
    int last = -1;
    f(26) {
        if (cnt[i] > (s.size() + 1) / 2) {
            cout << -1 << '\n';
            return;
        }
    }
    f(s.size()) {
        int mi = -1;
        int mu = -1;
        fr(j,0,26) {
            if (cnt[j] * 2 - 1 == s.size() - i) {
                mu = j;
                break;
            }
            if (cnt[j] && mi == -1 && j != last) {
                mi = j;
            }
        }
        if (~mu) {
            cout << char('A' + mu);
            cnt[mu]--;
            last = mu;
        }
        else {
            cout << char('A' + mi);
            cnt[mi]--;
            last = mi;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}