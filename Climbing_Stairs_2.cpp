class Solution
{
public:
    int space(int index, vector<int> &dp)
    {
        // TC: O(N)
        // SC:O(1)
        //  bottom up: bae case to required answer
        int prev2 = 1;
        int prev = 1;

        for (int i = 2; i <= index; i++)
        {
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    // int tab(int index, vector<int>& dp) {
    // TC:O(N)
    // SC:O(N)
    //     //bottom up: bae case to required answer
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     for (int i = 2; i <= index; i++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[index];
    // }
    // int solve(int index, vector<int>& dp) {
    // top down: required answer to base case
    // TC:O(N)
    // SC:O(N+N)
    //     // Base cases
    //     if (index == 0)
    //         return 1;
    //     if (index < 0)
    //         return 0;
    //     if (dp[index] != -1)
    //         return dp[index];

    //     // doing all the stuffs on the index acc. to problem
    //     int left = solve(index - 1, dp);
    //     int right = solve(index - 2, dp);

    //     return dp[index] = left + right;
    // }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        // return solve(n, dp);
        // return tab(n, dp);
        return space(n, dp);
    }
};