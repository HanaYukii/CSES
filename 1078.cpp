#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 2000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
const int mod = 1e9 + 7;
ll pre[maxn];
ll inv[maxn];
ll prei[maxn];
void build(int n){
    pre[1] = pre[0] = 1, inv[1] = inv[0] = 1, prei[1] = prei[0] = 1;
    for(int i = 2 ; i <= n ; i++){
        pre[i] = pre[i-1] * i % mod;
        inv[i] = (mod - mod / i * inv[mod % i] % mod) % mod;
        prei[i] = prei[i-1] * inv[i] % mod;
    }
}
ll C(int n, int k){
   return pre[n] * prei[k] % mod * prei[n-k] % mod;
}
ll pm(int n,int p){
    ll ret = 1;
    ll now = n;
    while(p){
        if(p & 1){
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        p >>= 1;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> k;
    m = n;
    vector<pair<int,int>>v(k);
    for (auto &i : v) {
        cin >> i.F >> i.S;
    }
    sort(all(v));
    build(n + m + 2);
    ll ans = C(n + m - 2, n - 1);
    ll dp[k + 5] = {};
    for (int i = 0 ; i < k ; i++) {
        dp[i] = C(v[i].F+v[i].S-2,v[i].F-1);
        fr(j,0,i) {
            if (v[j].S <= v[i].S) {
                dp[i] -= dp[j] * C(v[i].F+v[i].S-v[j].F-v[j].S, v[i].F - v[j].F) % mod;
                dp[i] += mod;
                dp[i] %= mod;
            }
        }
    }
    for (int i = 0 ; i < k ; i++) {
        dp[i] *= C(n + m - v[i].F - v[i].S , n - v[i].F);
        dp[i] %= mod;
        ans -= dp[i];
        ans += mod;
        ans %= mod;
    }
    cout << ans << endl;
}