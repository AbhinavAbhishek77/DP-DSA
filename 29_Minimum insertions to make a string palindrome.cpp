
// Mem
int solve(int i, int j, string &ptr, string &str, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (ptr[i - 1] == str[j - 1])
    {
        return dp[i][j] = 1 + solve(i - 1, j - 1, ptr, str, dp);
    }
    else
    {
        return dp[i][j] = max(solve(i, j - 1, ptr, str, dp), solve(i - 1, j, ptr, str, dp));
    }
}

int minimumInsertions(string &str)
{
    int n = str.size();

    string ptr = str;
    reverse(str.begin(), str.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return n - solve(n, n, ptr, str, dp);
}

// Tab
//dp[i][j] ==> till index [i][j] longest palindromic subsequence 
int minimumInsertions(string &str)
{
    int n = str.size();

    string ptr = str;
    reverse(str.begin(), str.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Base condn already satisfied while declaring dp

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ptr[i - 1] == str[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return n - dp[n][n];
}

// Space

int minimumInsertions(string &str)
{
    int n = str.size();

    string ptr = str;
    reverse(str.begin(), str.end());
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ptr[i - 1] == str[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return n - prev[n];
}
