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
vector<int>pre;
int pos[maxn];
struct node
{
    node* left;
    node* right;
    int val;
    node() {
        left = NULL;
        right = NULL;
        val = 0;
    }
};
node* build(int l, int r) {
    if (l > r) {
        return NULL;
    }
    node* ret = new node;
    ret->val = pre[l];
    int mid = l + 1;
    while (pos[pre[mid]] < pos[pre[l]] && mid <= r) {
        mid++;
    }
    ret->left = build(l+1,mid-1);
    ret->right = build(mid,r);
    return ret;
}
void post(node* x) {
    if (!x) {
        return;
    }
    post(x->left);
    post(x->right);
    cout << x -> val << ' ';
}
void solve() {
    int n;
    cin >> n;
    f(n) {
        int x;
        cin >> x;
        pre.pb(x);
    }
    f(n) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    node* x = build(0,n-1);
    post(x);
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