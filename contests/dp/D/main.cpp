#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_W = 100000;
int64_t dp[MAX_N + 1][MAX_W + 1];

int64_t solve(const int N, const int W, const vector<int64_t>& w, const vector<int64_t>& v) {
  // Initialize dp table
  for (auto i = 0; i <= MAX_W; ++i) {
    dp[0][i] = 0;
  }

  // dp
  for (auto i = 1; i <= N; ++i) {
    for (auto j = 0; j <= W; ++j) {
      if (j - w[i - 1] >= 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Find max value
  int64_t max_value = 0;
  for (auto i = 1; i <= MAX_W; ++i) {
    max_value = max(max_value, dp[N][i]);
  }

  return max_value;
}

int main() {
  // Input
  int N, W;

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
