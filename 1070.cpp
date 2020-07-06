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
int v[200005];
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        exit(0);
    }
    if (n <= 3) {
        cout << "NO SOLUTION\n";
        return;
    }
    for (int i = 2 ; i <= n ; i += 2) {
        cout << i <<' ';
    }
    for (int i = 1 ; i <= n ; i += 2) {
        cout << i <<' ';
    }
    
    cout << endl;
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