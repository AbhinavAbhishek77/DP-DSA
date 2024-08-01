 //Tabul.
 
 int solve(vector<int>& num, int x) {

        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(x + 1, -1));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int T = 0; T <= x; T++) {
            if (T % num[0] == 0) {
                dp[0][T] = T / num[0];
            } else
                dp[0][T] = INT_MAX;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= x; target++) {
                int notpick = dp[ind - 1][target];
                int pick = INT_MAX;
                if (num[ind] <= target) {
                    int res = dp[ind][target - num[ind]];
                    if (res != INT_MAX) {
                        pick = 1 + res;
                    }
                }
                dp[ind][target] = min(notpick, pick);
            }
        }
        int result = dp[n - 1][x];
        return result == INT_MAX ? -1 : result;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solve(coins, amount);
        return result == INT_MAX ? -1 : result;
    }


    //mem

    class Solution {
public:
    int solve(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return 0;
        }
        if (ind == 0) {
            return target % nums[ind] == 0 ? target / nums[ind] : INT_MAX;
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        int notpick = solve(nums, ind - 1, target, dp);
        int pick = INT_MAX;
        if (nums[ind] <= target) {
            int res = solve(nums, ind, target - nums[ind], dp);
            if (res != INT_MAX) {
                pick = 1 + res;
            }
        }

        return dp[ind][target] = min(notpick, pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solve(coins, n - 1, amount, dp);
        return result == INT_MAX ? -1 : result;
    }
};