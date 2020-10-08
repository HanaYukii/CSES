#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
struct VertexBCC { int stamp, bcc_num;
  struct Node : vector<int> { int dfn; vector<int> bcc; bool isC;
    Node() { dfn = -1, isC = false; bcc.clear(); }
  };
  vector<Node> N; vector<pii> stk;
  vector<vector<int> > BCC;
  void init(int n) {
    BCC.clear(); N.clear(); N.resize(n);
  }
  void addEdge(int u, int v) {
    N[u].push_back(v); N[v].push_back(u);
  }
  int Tarjan(int u, int p) {
    int lowu = N[u].dfn = stamp++, son = 0;
    for (auto &v : N[u]) if (!~N[v].dfn) {
      son++, stk.push_back({u, v});
      int lowv = Tarjan(v, u); lowu = min(lowu, lowv);
      if (lowv >= N[u].dfn) { N[u].isC = true;
        BCC.push_back({}); auto &B = BCC.back();
        while (1) { auto x=stk.back(); stk.pop_back();
          if (!N[x.F].bcc.size() || N[x.F].bcc.back() != bcc_num)
            B.push_back(x.F), N[x.F].bcc.push_back(bcc_num);
          if (!N[x.S].bcc.size() || N[x.S].bcc.back() != bcc_num)
            B.push_back(x.S), N[x.S].bcc.push_back(bcc_num);
          if (x.F == u && x.S == v) break;
        } bcc_num++;
      }
    } else if (N[v].dfn < N[u].dfn && v != p)
      stk.push_back({u, v}), lowu = min(lowu,N[v].dfn);
    if (!~p && son == 1) N[u].isC = false; return lowu;
  }
  void run() { stamp = bcc_num = 0;
    for (int i = 0 ; i < N.size() ; i++)
      if (!~N[i].dfn) Tarjan(i, -1);
  }
} solver;
void dfs(vector<vector<int>> &G, int u, int p, vector<int> &dep, vector<vector<int>> &pa) {
  dep[u] = dep[p] + 1; pa[0][u] = p;
  for (int h = 1 ; h < pa.size() ; h++) {
    pa[h][u] = pa[h - 1][pa[h - 1][u]];
  }
  for (auto &v : G[u]) {
    if (v == p)
      continue;
    dfs(G, v, u, dep, pa);
  }
}
int lca(int u, int v, vector<int> &dep, vector<vector<int>> &pa) {
  if (dep[u] < dep[v])
    swap(u, v);
  for (int h = pa.size() - 1 ; h >= 0 ; h--) {
    if (dep[pa[h][u]] >= dep[v])
      u = pa[h][u];
  }
  if (u == v)
    return u;
  for (int h = pa.size() - 1 ; h >= 0 ; h--) {
    if (pa[h][u] != pa[h][v])
      u = pa[h][u], v = pa[h][v];
  }
  return pa[0][u];
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m, q; cin >> n >> m >> q;
  solver.init(n);
  while (m--) {
    int u, v; cin >> u >> v; u--, v--;
    solver.addEdge(u, v);
  }
  solver.run();
  int st = solver.bcc_num;
  for (int i = 0 ; i < n ; i++) {
    if (solver.N[i].isC)
      solver.N[i].bcc.push_back(st++);
  }
  vector<vector<int>> G(st);
  for (int i = 0 ; i < n ; i++) {
    if (!solver.N[i].isC)
      continue;
    for (int j = 0 ; j < solver.N[i].bcc.size() - 1 ; j++) {
      G[solver.N[i].bcc[j]].push_back(solver.N[i].bcc.back());
      G[solver.N[i].bcc.back()].push_back(solver.N[i].bcc[j]);
    }
  }
  vector<int> dep(st, -1);
  vector<vector<int>> pa(__lg(st) + 1, vector<int>(st, -1));
  dfs(G, 0, 0, dep, pa);
  while (q--) {
    int a, b, c; cin >> a >> b >> c;
    a--, b--, c--;
    if (c == a || c == b) {
        cout << "NO\n";
        continue;
    }
    if (!solver.N[c].isC) {
      cout << "YES\n";
      continue;
    }
    a = solver.N[a].bcc.back();
    b = solver.N[b].bcc.back();
    c = solver.N[c].bcc.back();
    int lab = lca(a, b, dep, pa);
    int lbc = lca(b, c, dep, pa);
    int lac = lca(a, c, dep, pa);
    int dab = dep[a] + dep[b] - 2 * dep[lab];
    int dbc = dep[b] + dep[c] - 2 * dep[lbc];
    int dac = dep[a] + dep[c] - 2 * dep[lac];
    if (dab == dac + dbc)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}