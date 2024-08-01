// Both memoization and Tabulation
#include <bits/stdc++.h>
// int solve(vector<int>&w, vector<int>&v, int ind,int W,vector<vector<int>>&dp )
// {
// 	if(ind<0) return 0;

//    if(ind==0)
//    {
// 	   return dp[ind][W]=w[ind]<=W ? v[ind] : 0;
//    }
//     if(dp[ind][W]!=-1) return dp[ind][W];
//     int notpick=0 + solve(w,v,ind-1,W,dp);

// 	int pick=0;
// 	if(w[ind]<=W)
// 	{
// 		pick=v[ind] + solve(w,v,ind-1,W-w[ind],dp);
// 	}

// 	return dp[ind][W]=max(notpick, pick);

// }
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0)); // Here need to fill with 0 because
    // if we fill -1 then it may affect our answer because we are adding values by picking or not picking
    //  return solve(weight,value,n-1,maxWeight,dp);
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int notpick = 0 + dp[i - 1][W];

            int pick = 0;
            if (weight[i] <= W)
            {
                pick = value[i] + dp[i - 1][W - weight[i]];
            }
            dp[i][W] = max(notpick, pick);
        }
    }
    return dp[n - 1][maxWeight];
}

// Space Optimized

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);

    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int notpick = 0 + prev[W];

            int pick = 0;
            if (weight[i] <= W)
            {
                pick = value[i] + prev[W - weight[i]];
            }
            curr[W] = max(notpick, pick);
        }
        prev = curr;
    }
    return prev[maxWeight];
}
