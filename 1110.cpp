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
const int maxn = 2e5+5;
string mr (string s) {
    int n = s.size(), i = 0, j = 1, ans;
    s += s;
    while (i < n && j < n) {
        int k = 0;
        while (k < n && s[i + k] == s[j + k]) {
            k++;
        }
        if (s[i + k] <= s[j + k]) {
            j += k + 1;
        }
        else {
            i += k + 1;
        }
        if (i == j) {
            j++;
        }
    }
    return ans = i < n ? i : j,s.substr(ans, n);
}
void solve() {
    string s;
    cin >> s;
    cout << mr(s) << '\n';
}
int main() {
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