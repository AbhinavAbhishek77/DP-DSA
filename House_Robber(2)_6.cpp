#include <bits/stdc++.h> 
long long int space(vector<int>&nums, int ind)
{
    long long int prev=nums[0]; //dp[0]=nums[0];
   long long int prev2=0;

   for(int i=1;i<=ind;i++)
   {
       long long int pick=nums[i];
     if (i - 2 >= 0) {
       pick = nums[i] + prev2;
     }

       long long int notpick=0+prev;

       long long int curr=max(pick,notpick);
       prev2=prev;
       prev=curr;
   }
   return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    if(valueInHouse.size()==1) return valueInHouse[0];
    vector<int>temp1(valueInHouse.begin(), valueInHouse.end()-1), temp2(valueInHouse.begin()+1, valueInHouse.end());
    long long int ans1=space(temp1,temp1.size()-1);
    long long int ans2=space(temp2,temp2.size()-1);
    return max(ans1,ans2);
}