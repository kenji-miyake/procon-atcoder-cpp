#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 2000;
constexpr int MAX_A = 500000;
int64_t dp[MAX_N + 1][MAX_N + 1];  // Minimum total wins to accomplish N good conditions at day N

int64_t solve(const int64_t N, const int64_t K, const vector<int64_t>& a) {
  // Initialize DP table
  for (auto i = 0; i <= MAX_N; ++i) {
    for (auto j = 0; j <= MAX_N; ++j) {
      if (j == 0) {
        dp[i][j] = 0;
      } else if (j == 1) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = K + 1;
      }
    }
  }

  // Calculate sum games
  vector<int64_t> sum_games(N);
  partial_sum(begin(a), end(a), begin(sum_games));

  // DP
  int64_t total_games = accumulate(begin(a), end(a), 0);
  for (auto i = 2; i <= N; ++i) {
    for (auto j = 2; j <= i; ++j) {
      const int64_t min_wins = dp[i - 1][j - 1] * a[i - 1] / sum_games[i - 2] + 1;
      const auto total_wins = dp[i - 1][j - 1] + min_wins;
      const auto remain_wins = K - total_wins;
      const auto remain_games = total_games - sum_games[i - 1];

      // cout << i << ", " << j << endl;
      if (remain_wins <= remain_games && min_wins <= a[i - 1]) {
        dp[i][j] = min(dp[i - 1][j], total_wins);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Find max days
  int64_t max_days = 0;
  for (auto i = 0; i <= MAX_N; ++i) {
    if (dp[N][i] <= K) {
      max_days = i;
    }
  }

  return max_days;
}

int main() {
  // Input
  int64_t N, K;
  cin >> N >> K;

  vector<int64_t> a(N);
  for (auto i = 0; i < N; ++i) {
    cin >> a[i];
  }

  // Solve
  auto ans = solve(N, K, a);

  // Answer
  cout << ans << endl;

  return 0;
}
