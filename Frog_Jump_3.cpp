#include <bits/stdc++.h>
// int rec(int ind, vector<int>&h)
// {
//  if(ind==0) return 0;

//  int left=rec(ind-1,h)+abs(h[ind]-h[ind-1]);
//  int right=INT_MAX;
//  if (ind > 1) {
//    right = rec(ind - 2, h) + abs(h[ind] - h[ind - 2]);
//  }

//  return min(left,right);

// }

// int mem(int ind, vector<int>&h, vector<int>&dp)
// {
//  if(ind==0) return 0;
//  if(dp[ind]!=-1) return dp[ind];

//  int left=mem(ind-1,h,dp)+abs(h[ind]-h[ind-1]);
//  int right=INT_MAX;
//  if (ind > 1) {
//    right = mem(ind - 2, h,dp) + abs(h[ind] - h[ind - 2]);
//  }

//  return dp[ind]=min(left,right);

// }

// int tab(int ind, vector<int>&h, vector<int>&dp)
// {
// //bottom-up

// dp[0]=0;

// for(int i=1;i<=ind;i++)
// {
//     int left=dp[i-1]+abs(h[i]-h[i-1]);
//  int right=INT_MAX;
//  if (i > 1) {
//    right = dp[i - 2] + abs(h[i] - h[i - 2]);
//  }
//  dp[i] = min(left, right);
// }
// return dp[ind];
// }

int space(int ind, vector<int> &h)
{
    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i <= ind; i++)
    {
        int left = prev + abs(h[i] - h[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = prev2 + abs(h[i] - h[i - 2]);
        }
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int frogJump(int n, vector<int> &heights)
{
    // return rec(n-1,heights);
    // vector<int>dp(n,-1);
    // return mem(n-1,heights,dp);
    // return tab(n-1,heights,dp);
    return space(n - 1, heights);
}
