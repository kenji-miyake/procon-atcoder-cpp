#include <bits/stdc++.h>
using namespace std;

constexpr int64_t MAX_N = 100;
constexpr int64_t MAX_V = 1000;
constexpr int64_t MAX_SUM_V = MAX_N * MAX_V;
int64_t dp[MAX_N + 1][MAX_SUM_V + 1];

int64_t solve(const int64_t N, const int64_t W, const vector<int64_t>& w, const vector<int64_t>& v) {
  // Initialize dp table
  dp[0][0] = 0;
  for (auto i = 1; i <= N * MAX_V; ++i) {
    dp[0][i] = W + 1;
  }

  // dp
  for (auto i = 1; i <= N; ++i) {
    for (auto j = 0; j <= N * MAX_V; ++j) {
      if (j - v[i - 1] >= 0) {
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Find max_value
  int64_t max_value = 0;
  for (auto i = 1; i <= N * MAX_V; ++i) {
    if (dp[N][i] <= W) {
      max_value = i;
    }
  }

  return max_value;
}

int main() {
  // Input
  int64_t N, W;

  cin >> N >> W;

  vector<int64_t> w(N), v(N);
  for (auto i = 0; i < N; ++i) {
    cin >> w[i] >> v[i];
  }

  // Solve
  auto ans = solve(N, W, w, v);

  // Answer
  cout << ans << endl;

  return 0;
}
