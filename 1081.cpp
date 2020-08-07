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
 
vector<int>fac[1000005];
int cnt[1000005];
void solve() {
    int n;
    cin >> n;
    f(n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1000000 ; i >= 1 ; i--) {
        int tot = 0;
        for (int j = i ; j <= 1000000; j += i) {
            tot += cnt[j];
        }
        if (tot >= 2) {
            cout << i << endl;
            exit(0);
        }
    }
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