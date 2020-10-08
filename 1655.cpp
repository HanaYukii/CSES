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
const int maxn = 3e6+5;
struct node
{
    node() {
        ch[0] = ch[1] = 0;
    }
    int ch[2];
}node[maxn];
int idx;
void add(int x) {
    int pos = 0;
    for (int i = 30 ; i >= 0 ; i--) {
        if (x & (1<<i)) {
            if (node[pos].ch[1]) {
                pos = node[pos].ch[1];
            }
            else {
                node[pos].ch[1] = ++idx;
                pos = idx;
            }
        }
        else {
            if (node[pos].ch[0]) {
                pos = node[pos].ch[0];
            }
            else {
                node[pos].ch[0] = ++idx;
                pos = idx;
            }
        }
    }
}
int find(int x) {
    int pos = 0;
    int ret = 0;
    for (int i = 30 ; i >= 0 ; i--) {
        if (x & (1<<i)) {
            if (node[pos].ch[0]) {
                ret += (1<<i);
                pos = node[pos].ch[0];
            }
            else {
                pos = node[pos].ch[1];;
            }
        }
        else {
            if (node[pos].ch[1]) {
                ret += (1<<i);
                pos = node[pos].ch[1];
            }
            else {
                pos = node[pos].ch[0];;
            }
        }
    }
    return ret;
}
void solve() {
    add(0);
    int n;
    int mx = 0;
    int cur = 0;
    cin >> n;
    f(n) {
        int x;
        cin >> x;
        cur ^= x;
        mx = max(mx, find(cur));
        add(cur);
    }
    cout << mx << '\n';
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