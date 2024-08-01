#include <bits/stdc++.h> 
// int rec(vector<int>&nums, int ind)
// {
//     if(ind==0) return nums[ind];
//     if(ind<0) return 0;

//     int pick=nums[ind] + rec(nums,ind-2);

//     int notpick=0 + rec(nums,ind-1);

//     return max(pick,notpick);
// }

// int mem(vector<int>&nums, int ind, vector<int>&dp)
// {
//     if(ind==0) return nums[ind];
//     if(ind<0) return 0;
//     if(dp[ind]!=-1) return dp[ind];

//     int pick=nums[ind] + mem(nums,ind-2,dp);

//     int notpick=0 + mem(nums,ind-1,dp);

//     return dp[ind]=max(pick,notpick);
// }

// int tab(vector<int>&nums, int ind, vector<int>&dp)
// {
//     dp[0]=nums[0];
//     // if(ind<0) return 0;
//     // if(dp[ind]!=-1) return dp[ind];

//    for(int i=1;i<=ind;i++)
//    {
//        int pick=nums[i];
//      if (i - 2 >= 0) {
//        pick = nums[i] + dp[i - 2];
//      }

//        int notpick=0+dp[i-1];

//        dp[i]=max(pick,notpick);
//    }
//    return dp[ind];
// }

int space(vector<int>&nums, int ind)
{
    int prev=nums[0];; //dp[0]=nums[0];
   int prev2=0;

   for(int i=1;i<=ind;i++)
   {
       int pick=nums[i];
     if (i - 2 >= 0) {
       pick = nums[i] + prev2;
     }

       int notpick=0+prev;

       int curr=max(pick,notpick);
       prev2=prev;
       prev=curr;
   }
   return prev;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    // return rec(nums,n-1);
    vector<int>dp(n+1,-1);
    // dp[i] represents max non adjacent sum till index

    // return mem(nums,n-1,dp);
    // return tab(nums,n-1,dp);

    return space(nums,n-1);

}