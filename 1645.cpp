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
int ans[200005];
int v[200005];
void solve() {
    int n;
    cin >> n;
    stack<int>st;
    st.push(n);
    f1(n) {
        cin >> v[i];
    }
    for (int i = n - 1 ; i >= 1 ; i--) {
        while (st.size() && v[i] < v[st.top()]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    f1(n) {
        cout << ans[i] <<' ';
    }
    cout << '\n';
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