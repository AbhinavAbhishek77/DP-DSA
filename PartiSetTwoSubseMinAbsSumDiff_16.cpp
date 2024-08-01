// Best Approach

int minSubsetSumDifference(vector<int> &arr, int n)
{

    int totalSum = 0;
    for (auto v : arr)
        totalSum += v;

    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= totalSum)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= totalSum / 2; target++)
        {
            bool notpick = dp[ind - 1][target];

            bool pick = false;
            if (arr[ind] <= target)
            {
                pick = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = pick | notpick;
        }
    }

    int mini = INT_MAX;
    for (int i = 0; i <= totalSum / 2; i++)
    {
        if (dp[n - 1][i])
        {
            int s1 = i;
            int s2 = totalSum - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}



// By own
/*int mini=INT_MAX;
int mem(vector<int>& arr, int ind,int target,int sum, vector<vector<int>>& dp)
{
//for index 0 also, we have kept condition to pick or not pick
// whenever we will be at ind<0 , we will have possible subsequence
   // Base case: when ind < 0, we have a possible subsequence
    if (ind < 0) {
        int x = target;
        int y = sum - target;
        return abs(y - x);
    }

   // Check if this state has already been computed
    if (dp[ind][target] != -1) {
        return dp[ind][target];
    }

 // Consider both cases: including arr[ind] and not including arr[ind]
    int include = mem(arr, ind - 1, target - arr[ind], sum, dp);
    int exclude = mem(arr, ind - 1, target, sum, dp);

	// Store the minimum difference in dp table
    return dp[ind][target] = min(include, exclude);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    
	int target=0;
	for(auto v:arr) target+=v;

	 // Initialize dp table with -1 (indicating uncomputed states)
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    int sum=target;
	return mem(arr,n-1,target,sum,dp);
	
}
/*