#include <bits/stdc++.h>
using namespace std;

vector<int> getAllValues(const int N, const int v) {
  vector<int> all_values;

  int current = v;
  while (current <= N) {
    all_values.push_back(current);
    current *= v;
  }

  return all_values;
}

int solve(const int N) {
  // Get all values
  vector<int> all_values{1};
  for (const auto v : getAllValues(N, 6)) {
    all_values.push_back(v);
  }
  for (const auto v : getAllValues(N, 9)) {
    all_values.push_back(v);
  }

  // Sort in descent order
  sort(begin(all_values), end(all_values), greater<int>());

  // Initialize DP
  vector<int> dp(N + 1, N);
  dp[0] = 0;

  // DP
  for (auto i = 0; i < N; ++i) {
    for (const auto v : all_values) {
      if (i + v > N) {
        continue;
      }

      dp[i + v] = min(dp[i + v], dp[i] + 1);
    }
  }

  return dp[N];
}

int main() {
  // Input
  int N;
  cin >> N;

  // Solve
  auto ans = solve(N);

  // Answer
  cout << ans << endl;

  return 0;
}
