// Space

int lcs(string s, string t)
{
    int n = s.size(), m = t.size();
    int i1 = n, i2 = m;

    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // base case
    for (int j = 0; j <= m; j++)
    {
        prev[j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(curr[j - 1], prev[j]);
            }
        }
        prev = curr;
    }
    return prev[m];
}

// Tabulation

int lcs(string s, string t)
{
    int n = s.size(), m = t.size();
    int i1 = n, i2 = m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base case
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][m];
}

// Memoization
// Base Case Changed
#include <bits/stdc++.h>
int solve(string s, string t, int i1, int i2, vector<vector<int>> &dp)
{
    if (i1 == 0 || i2 == 0)
    {
        return 0;
    }
    if (dp[i1][i2] != -1)
    {
        return dp[i1][i2];
    }

    if (s[i1 - 1] == t[i2 - 1])
    {
        return 1 + solve(s, t, i1 - 1, i2 - 1, dp);
    }
    else
    {
        return dp[i1][i2] = max(solve(s, t, i1, i2 - 1, dp), solve(s, t, i1 - 1, i2, dp));
    }
}

int lcs(string s, string t)
{
    int n = s.size(), m = t.size();
    int i1 = n, i2 = m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(s, t, i1, i2, dp);
}

// Initially==>mem
//  #include<bits/stdc++.h>
//  int solve(string s, string t,int i1, int i2,vector<vector<int>>&dp)
//  {
//          if(i1<0 || i2<0)
//  		{
//  			return 0;
//  		}
//           if(dp[i1][i2]!=-1)
//  		 {
//  			 return dp[i1][i2];
//  		 }

//        int x=0,y=0,z=0;
//        if(s[i1]==t[i2])
// 	   {
// 		   return 1+solve(s,t,i1-1,i2-1,dp);
// 		//    return dp[i1][i2]=x;
// 	   }
//        else
// 	   {
// 		   return dp[i1][i2]=max(solve(s,t,i1,i2-1,dp),solve(s,t,i1-1,i2,dp));
// 		//    return dp[i1][i2]=max(y,z);
// 	   }

// 	//    return dp[i1][i2]=max(x,max(y,z));

// }

// int lcs(string s, string t)
// {
// 	int n=s.size(),m=t.size();
// 	int i1=n-1,i2=m-1;

// 	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
// 	return solve(s,t,i1,i2,dp);
// }