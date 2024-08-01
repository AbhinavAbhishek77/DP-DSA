
// mem
class Solution
{
public:
    int solve(vector<int> &nums, int ind, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
            return 1;
        if (ind == 0)
        {
            return target % nums[0] == 0 ? 1 : 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notpick = 0 + solve(nums, ind - 1, target, dp);
        int pick = 0;
        if (nums[ind] <= target)
        {
            pick = solve(nums, ind, target - nums[ind], dp);
        }

        return dp[ind][target] = notpick + pick;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(coins, n - 1, amount, dp);
    }
};

// tab

long long int count(int coins[], int N, int sum)
{
    vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, 0));

    for (int i = 0; i < N; i++)
    {
        dp[i][0] = 1;
    }

    for (int target = 0; target <= sum; target++)
    {
        if (target % coins[0] == 0)
            dp[0][target] = 1;
        else
            dp[0][target] = 0;
    }

    for (int ind = 1; ind < N; ind++)
    {
        for (int target = 0; target <= sum; target++)
        {
            long long int notpick = dp[ind - 1][target];
            long long int pick = 0;
            if (coins[ind] <= target)
            {
                pick = dp[ind][target - coins[ind]];
            }
            dp[ind][target] = notpick + pick;
        }
    }

    return dp[N - 1][sum];
}

// Space

long int solve(int *arr, int N, int sum)
{
    // vector<vector<long long int>>dp(N, vector<long long int>(sum+1, 0));
    vector<long> prev(sum + 1, 0), curr(sum + 1, 0);

    //  for(int i=0;i<N;i++)
    //  {
    //  prev[0]=1;
    //  }

    for (int target = 0; target <= sum; target++)
    {
        if (target % arr[0] == 0)
            prev[target] = 1;
        else
            prev[target] = 0;
    }

    for (int ind = 1; ind < N; ind++)
    {
        for (int target = 0; target <= sum; target++)
        {
            long int notpick = prev[target];
            long int pick = 0;
            if (arr[ind] <= target)
            {
                pick = curr[target - arr[ind]];
            }
            curr[target] = notpick + pick;
        }
        prev = curr;
    }

    return prev[sum];
}

long countWaysToMakeChange(int *denominations, int n, int value)
{

    return solve(denominations, n, value);
}