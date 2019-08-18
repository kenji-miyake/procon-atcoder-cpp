#include <bits/stdc++.h>
using namespace std;

void spreadCountToChildren(const vector<vector<int>>& all_connected_nodes, vector<int>& counter, const int node,
                           const int parent_node) {
  for (const auto& connected_node : all_connected_nodes[node]) {
    if (connected_node != parent_node) {
      counter[connected_node - 1] += counter[node - 1];
      spreadCountToChildren(all_connected_nodes, counter, connected_node, node);
    }
  }
}

vector<int> solve(const int N, const int Q, const vector<int>& a, const vector<int>& b, const vector<int>& p,
                  const vector<int>& x) {
  // Save connected nodes
  vector<vector<int>> all_connected_nodes(N + 1, vector<int>{});
  for (auto i = 0; i < N - 1; ++i) {
    all_connected_nodes[a[i]].push_back(b[i]);
    all_connected_nodes[b[i]].push_back(a[i]);
  }

  // Apply each count
  vector<int> counter(N, 0);
  for (auto j = 0; j < Q; ++j) {
    counter[p[j] - 1] += x[j];
  }

  // Spread count to children using DFS
  spreadCountToChildren(all_connected_nodes, counter, 1, -1);

  return counter;
}

int main() {
  // Input
  int N, Q;
  cin >> N >> Q;

  vector<int> a(N - 1), b(N - 1);
  for (auto i = 0; i < N - 1; ++i) {
    cin >> a[i] >> b[i];
  }

  vector<int> p(Q), x(Q);
  for (auto j = 0; j < Q; ++j) {
    cin >> p[j] >> x[j];
  }

  // Solve
  auto ans = solve(N, Q, a, b, p, x);

  // Answer
  for (const auto& c : ans) {
    cout << c << " ";
  }
  cout << endl;

  return 0;
}
