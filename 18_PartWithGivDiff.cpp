#include <bits/stdc++.h> 


//mem
// const int mod = 1000000007;

// int solve(vector<int> &arr, int k, int ind, vector<vector<int>> &dp)
// {
//     // if(k==0) return 1;
//      if(ind==0){
//             if(k==0)
//             {
//                 if(arr[ind]==0)return 2;
//                 return 1;
//             }
//             if(k==0 || k==arr[ind] )
//                 return 1;
//             return 0;
           
//  }


//     if (dp[ind][k] != -1)
//         return dp[ind][k];
//     int l = solve(arr, k, ind - 1, dp) % mod;
//     int r = 0;
//     if (arr[ind] <= k)
//         r = solve(arr, k - arr[ind], ind - 1, dp) % mod;

//     dp[ind][k] = (l + r) % mod;
//     return dp[ind][k];
// }

// int findWays(vector<int> &arr, int k)
// {
//     // Write your code here.
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//     return solve(arr, k, n - 1, dp);
// }

// int countPartitions(int n, int d, vector<int> &arr) {
//   int totalsum=0;
//   for(auto v:arr)
//   {
//       totalsum+=v;
//   }

//  //Checking for edge cases
//     if(totalsum-d<0) return 0;
//     if((totalsum-d)%2==1) return 0;
    
//     int s2 = (totalsum-d)/2;

//   return findWays(arr,s2);
// }

//tab
const int mod = 1000000007;

int findWays(vector<int> &arr, int k) {
    int n = arr.size();

    // Create a 2D DP table with dimensions n x k+1, initialized with zeros
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    
    // Base case: Initializing the DP table for the first element
    if (arr[0] == 0) {
        dp[0][0] = 2;  // Two cases: pick and not pick the zero
    } else {
        dp[0][0] = 1;  // One case: not pick the first element
    }
    
    if (arr[0] != 0 && arr[0] <= k) {
        dp[0][arr[0]] = 1;  // One case: pick the first element
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= k; target++) {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            // Update the DP table
            dp[ind][target] = (notTaken + taken) % mod;
        }
    }

    // The final result is in the last cell of the DP table
   return dp[n-1][k];
}

int countPartitions(int n, int d, vector<int> &arr) {

  int totalsum=0;
  for(auto v:arr)
  {
      totalsum+=v;
  }

 //Checking for edge cases
    if(totalsum-d<0) return 0;
    if((totalsum-d)%2==1) return 0;
    
    int s2 = (totalsum-d)/2;
     vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
     return findWays(arr, s2);



}
