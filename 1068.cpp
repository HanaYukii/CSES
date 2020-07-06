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
void print(ll x) {
    cout << x <<' ';
    if (x == 1) {
        cout << '\n';
        return;
    }
    else if (x % 2) {
        print(x * 3 + 1);
    }
    else {
        print(x / 2);
    }
}
void solve() {
    int n;
    cin >> n;
    print(n);
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