#include <bits/stdc++.h>
using namespace std;
int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};
void solve(int x, int y, int dep, int S[8][8], int R[8][8]) {
    S[x][y] = dep;
    if (dep == 64) {
        for (int i = 0 ; i < 8 ; i++)
            for (int j = 0 ; j < 8 ; j++)
                cout << S[i][j] << " \n"[j + 1 == 8];
        exit(0);
    }
    vector<int> tar;
    for (int d = 0 ; d < 8 ; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
            continue;
        if (~S[nx][ny])
            continue;
        tar.push_back(d);
        R[x][y]--;
        R[nx][ny]--;
    }
    sort(tar.begin(), tar.end(), [&](int a, int b) {
        return R[x + dx[a]][y + dy[a]] < R[x + dx[b]][y + dy[b]];
    });
    for (auto &d : tar) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        solve(nx, ny, dep + 1, S, R);
    }
    S[x][y] = -1;
    for (int d = 0 ; d < 8 ; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
            continue;
        if (~S[nx][ny])
            continue;
        R[x][y]++;
        R[nx][ny]++;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int R[8][8] = {};
    for (int x = 0 ; x < 8 ; x++) {
        for (int y = 0 ; y < 8 ; y++) {
            for (int d = 0 ; d < 8 ; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
                    continue;
                R[x][y]++;
            }
        }
    }
    int x, y; cin >> x >> y; x--, y--;
    swap(x, y);
    int S[8][8];
    memset(S, -1, sizeof(S));
    solve(x, y, 1, S, R);
}