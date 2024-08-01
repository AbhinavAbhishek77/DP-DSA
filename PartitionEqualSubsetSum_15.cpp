// bool mem(vector<int> &arr, int ind, int target,vector<vector<int>>&dp)
// {
//     if(ind==0) 
//     {
//         if(target==0) return true;
//         else return false;
//     }
// 	if(dp[ind][target]!=-1) return dp[ind][target];

// bool pick=false;
// if(arr[ind]<=target)
// {
//      pick=mem(arr,ind-1,target-arr[ind],dp);
// }
//    bool notpick=mem(arr,ind-1,target,dp);



// return dp[ind][target]=pick | notpick;
   


// }

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int totalSum=0;
	for(auto v:arr) totalSum+=v;
	if(totalSum%2!=0) return false;

// int target=totalSum/2;
	// vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
	// return mem(arr,n-1,target,dp);

int k=totalSum/2;
		vector<vector<bool>>dp(n+1,vector<bool>(k+1,false));
//    cout<<n<<endl;
                for (int i = 0; i < n; i++) {
                  dp[i][0] = true;
				//   cout<<i<<0<<"="<<dp[i][0]<<endl;
                }

                if(arr[0]<=k) dp[0][arr[0]]=true;

		for(int ind=1;ind<n;ind++)
		{
			for(int target=1;target<=k;target++)
			{
				bool notpick=dp[ind-1][target];

				bool pick=false;
				if(arr[ind]<=target)
				{
					pick=dp[ind-1][target-arr[ind]];
				}

				dp[ind][target]=pick | notpick;
			}
		}
		
		return dp[n-1][k];

	
}
