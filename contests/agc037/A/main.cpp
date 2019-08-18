#include <bits/stdc++.h>
using namespace std;

int solve(const string& S) {
  // Initialize DP table
  const auto s_len = S.size();
  vector<int> dp(s_len, 0);

  dp[0] = 1;

  if (S.size() >= 2) {
    dp[1] = S.at(1) != S.at(0) ? 2 : 1;
  }

  if (S.size() >= 3) {
    dp[2] = (S.at(2) != S.at(1) && S.at(1) != S.at(0)) ? 3 : 2;
  }

  // DP
  for (auto i = 3; i < s_len; ++i) {
    if (S[i] != S[i - 1]) {
      dp[i] = max(dp[i], dp[i - 1] + 1);
    } else {
      dp[i] = max(dp[i], dp[i - 3] + 2);
    }
  }

  return dp[s_len - 1];
}

int main() {
  // Input
  string S;
  cin >> S;

  // Solve
  auto ans = solve(S);

  // Answer
  cout << ans << endl;

  return 0;
}
