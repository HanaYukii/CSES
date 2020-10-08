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
const ll mod = 1e11 + 7;
const int maxn = 2e5+5;
vector<int> Z(string &s) { int L = 0, R = 0;
    vector<int> z(s.size()); z[0] = s.size();
    for (int i = 1 ; i < (int)s.size() ; i++) {
        if (i <= R && z[i - L] <= R - i) z[i] = z[i - L];
        else { 
            L = i; 
            if (i > R) R = i;
            while (R < z[0] && s[R - L] == s[R]) R++;
            z[i] = (R--) - L;
        }
    }
    return z;
}
void solve() {
    string s;
    cin >> s;
    vector<int>z = Z(s);
    int n = s.size();
    for (int i = 1 ; i < n ; i++) {
        if (z[i] == n - i) {
            cout << i <<' ';
        }
    }
    cout << n << '\n';
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