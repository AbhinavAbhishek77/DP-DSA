
// Mem
int solve(vector<int> &w, vector<int> &v, int ind, int W, vector<vector<int>> &dp)
{
    if (ind < 0)
        return 0;

    // either you keep this condition or remove , no issue (There will be only difference in time)
    // means loop will keep running at ind=0 if the base condition satisfy
    if (ind == 0)
    {
        return (W / w[0]) * v[0];
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];
    int notpick = 0 + solve(w, v, ind - 1, W, dp);

    int pick = 0;
    if (w[ind] <= W)
    {
        pick = v[ind] + solve(w, v, ind, W - w[ind], dp);
    }

    return dp[ind][W] = max(notpick, pick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(weight, profit, n - 1, w, dp);
}

// Tab

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{

    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    // Base Case
    for (int wt = 0; wt <= w; wt++)
    {
        dp[0][wt] = (int)(wt / weight[0]) * profit[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int notpick = 0 + dp[ind - 1][wt];
            int pick = 0;
            if (weight[ind] <= wt)
            {
                pick = profit[ind] + dp[ind][wt - weight[ind]];
            }
            dp[ind][wt] = max(notpick, pick);
        }
    }
    return dp[n - 1][w];
}

// Space

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{

    // vector<vector<int>>dp(n,vector<int>(w+1,0));
    vector<int> prev(w + 1, 0), curr(w + 1, 0);

    // Base Case
    for (int wt = 0; wt <= w; wt++)
    {
        prev[wt] = (int)(wt / weight[0]) * profit[0];
        // put dp[0] as prev
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int notpick = 0 + prev[wt];
            int pick = 0;
            if (weight[ind] <= wt)
            {
                pick = profit[ind] + curr[wt - weight[ind]];
            }
            curr[wt] = max(notpick, pick);
        }
        prev = curr;
    }
    return prev[w];
}