// Tab

int lcs(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //   for (int i = 0; i <= n; i++) {
    //     dp[i][0] = 0;
    //   }
    //   for (int i = 0; i <= m; i++) {
    //     dp[0][i] = 0;
    //   }

    int ans = 0;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (str1[ind1 - 1] == str2[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                ans = max(ans, dp[ind1][ind2]);
            }
            else
                dp[ind1][ind2] = 0;
        }
    }
    return ans;
}

// Space

int lcs(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();

    //   vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    int ans = 0;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (str1[ind1 - 1] == str2[ind2 - 1])
            {
                curr[ind2] = 1 + prev[ind2 - 1];
                ans = max(ans, curr[ind2]);
            }
            else
                curr[ind2] = 0;
        }
        prev = curr;
    }
    return ans;
}
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    return lcs(S1, S2);
}