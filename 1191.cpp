#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
const LL MOD = 1e9 + 7;
int sp[200005][20];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    long long k;
    cin >> k;
    vector<LL> arr(n);
    for (auto &v : arr)
        cin >> v;
    vector<long long>pre{0};
    for (auto &i : arr) {
        pre.push_back(pre.back() + i);
    }
    for (auto &i : arr) {
        pre.push_back(pre.back() + i);
    }
    for (int i = 0 ; i < n ; i++) {
        int r = n + 1;
        int l = 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            //cout << i + mid << endl;
            if (pre[i + mid] > pre[i] + k) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        sp[i][0] = l;
        //cout << l << endl;
    }
    for (int i = 1 ; i < 20 ; i++) {
        for (int j = 0 ; j < n ; j++) {
            sp[j][i] = min(sp[j][i - 1] + sp[(sp[j][i-1] + j) % n][i - 1],n);
        }
    }
    //cout << "here" << endl;
    int ans = n;
    for (int i = 0 ; i < n ; i++) {
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            int ans = 0;
            int cur = 0;
            LL pos = i;
            int tm = mid;
            while (mid) {
                //cout << pos <<' '<<cur <<' '<<mid << endl;
                if (mid & 1) {
                    ans += sp[pos][cur];
                    pos += sp[pos][cur];
                    //cout << pos <<' '<<cur << ' '<<sp[pos][cur] << endl;
                    pos %= n;
                }
                cur++;
                mid >>= 1;
            }
            if (ans >= n) {
                r = tm;
            }
            else {
                l = tm;
            }
        }
        ans = min(ans, r);
    }
    cout << ans << '\n';
}