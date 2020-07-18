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
const int maxn = 2000005;
int pa[200005][20];
int in[200005];
int cy[200005];
int ans[200005];
void solve() {
    int n;
    cin >> n;
    f1(n) {
        cin >> pa[i][0];
        in[pa[i][0]] = 1;
    }
    f1(19) {
        fr(j,1,n+1) {
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    f1(n) {
        cy[pa[i][19]] = 1;
    }
    f1(n) {
        if (cy[i]==1 && !ans[i]) {
            vector<int>cycle{i};
            do{
                cycle.push_back(pa[cycle.back()][0]);
            }while (cycle.back() != i);
            for (auto &j : cycle) {
                ans[j] = cycle.size() - 1;
            }
        }
    }
    f1(n) {
        if (!in[i]) {
            vector<int>link{i};
            while (!cy[link.back()]) {
                link.pb(pa[link.back()][0]);
            }
            for (int j = 0 ; j < link.size() - 1 ; j++) {
                ans[link[j]] = link.size()-j-1 + ans[link.back()];
            }
        }
    }
    f1(n) {
        cout << ans[i] << ' ';
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