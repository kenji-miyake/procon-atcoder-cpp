#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 50;
constexpr int MAX_W = 10000;
int dp[MAX_N + 1][MAX_N + 1][MAX_W + 1];

int solve(const int W, const int N, const int K, const vector<int>& A, const vector<int>& B) {
  // Initialize
  for (auto w = 0; w <= W; ++w) {
    dp[0][0][w] = 0;
  }

  // DP
  for (auto n = 1; n <= N; ++n) {
    for (auto k = 1; k <= K; ++k) {
      for (auto w = 0; w <= W; ++w) {
        if (w - A[n] >= 0) {
          dp[n][k][w] = max(dp[n - 1][k][w], dp[n - 1][k - 1][w - A[n]] + B[n]);
        } else {
          dp[n][k][w] = dp[n - 1][k][w];
        }
      }
    }
  }

  // Find max value
  int max_value = 0;
  for (auto k = 0; k <= K; ++k) {
    max_value = max(max_value, dp[N][k][W]);
  }

  return max_value;
}

int main() {
  // Input
  int W;
  int N, K;

  cin >> W;
  cin >> N >> K;

  vector<int> A(N + 1), B(N + 1);

  for (auto n = 1; n <= N; ++n) {
    cin >> A[n] >> B[n];
  }

  // Solve
  auto ans = solve(W, N, K, A, B);

  // Answer
  cout << ans << endl;

  return 0;
}
