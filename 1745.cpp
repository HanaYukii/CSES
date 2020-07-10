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
    bitset<100001>b;
    b.reset();
    b.set(0);
    f(n) {
        int x;
        cin >> x;
        b |= (b << x);
    }
    cout << b.count() -1 << '\n';
    for (int i = 1 ; i <= 100000 ; i++) {
        if (b[i]) {
            cout << i <<' ';
        }
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