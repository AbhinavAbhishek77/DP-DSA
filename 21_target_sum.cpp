// Doesnt work for large testcases

#include <bits/stdc++.h>
int solve(vector<int> &arr, int ind, int target, int sum)
{

    if (ind == 0)
    {
        return sum - arr[ind] == target || sum + arr[ind] == target ? 1 : 0;
    }

    int minus = solve(arr, ind - 1, target, sum - arr[ind]);
    int plus = solve(arr, ind - 1, target, sum + arr[ind]);

    return minus + plus;
}
int targetSum(int n, int target, vector<int> &arr)
{

    return solve(arr, n - 1, target, 0);
}

// Tab

int targetSum(int n, int target, vector<int> &arr)
{
    int sum = 0;
    int d = target;
    for (auto v : arr)
        sum += v;

    if (sum - d < 0)
        return 0;
    if ((sum - d) % 2 == 1)
        return 0;
    int s1 = (sum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(s1 + 1, 0));
    // Base case: Initializing the DP table for the first element
    if (arr[0] == 0)
    {
        dp[0][0] = 2; // Two cases: pick and not pick the zero
    }
    else
    {
        dp[0][0] = 1; // One case: not pick the first element
    }

    if (arr[0] != 0 && arr[0] <= s1)
    {
        dp[0][arr[0]] = 1; // One case: pick the first element
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int t = 0; t <= s1; t++)
        {
            int notpick = dp[ind - 1][t];
            int pick = 0;
            if (arr[ind] <= t)
            {
                pick = dp[ind - 1][t - arr[ind]];
            }
            dp[ind][t] = notpick + pick;
        }
    }

    return dp[n - 1][s1];
}
