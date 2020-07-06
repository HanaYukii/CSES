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
    int n;
    cin >> n;
    multiset<int>st;
    f(n) {
        int x;
        cin >> x;
        if (st.upper_bound(x) == st.end()) {
            st.insert(x);
        }
        else {
            st.erase(st.upper_bound(x));
            st.insert(x);
        }
    }
    cout << st.size() << '\n';
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