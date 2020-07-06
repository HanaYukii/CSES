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
    int x, n;
    cin >> x >> n;
    multiset<int>sz;
    multiset<int>st;
    st.insert(0);
    st.insert(x);
    sz.insert(x);
    f(n) {
        cin >> x;
        int up = *st.upper_bound(x);
        int low = *prev(st.upper_bound(x));
        sz.erase(sz.find(up-low));
        st.insert(x);
        sz.insert(up-x);
        sz.insert(x-low);
        cout << *sz.rbegin() <<' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
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