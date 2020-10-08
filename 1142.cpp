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
    stack<int>st;
    int v[n + 2] = {};
    f1 (n) {
        cin >> v[i];
    }
    v[0] = v[n + 1];
    int l[n + 5] = {};
    int r[n + 5] = {};
    st.push(0);
    f1(n) {
        while (v[st.top()] >= v[i]) {
            st.pop();
        }
        l[i] = st.top();
        st.push(i);
    }
    while(st.size()) {
        st.pop();
    }
    st.push(n + 1);
    for (int i = n ; i >= 1 ; i--) {
        while (v[st.top()] >= v[i]) {
            st.pop();
        }
        r[i] = st.top();
        st.push(i);
    }
    ll mx = 0;
    f1(n) {
        mx = max(mx, (ll)v[i] * (r[i] - l[i] - 1));
    }
    cout << mx << '\n';
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