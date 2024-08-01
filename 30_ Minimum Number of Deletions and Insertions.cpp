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

int canYouMake(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int a = solve(n, m, s1, s2, dp);
    //  cout<<a<<endl;
    return (n - a) + (m - a);
}

// Tab
// dp[i][j] ==> till index [i][j] longest palindromic subsequence
int solve(int n, int m, string &ptr, string &str)
{

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base condn already satisfied while declaring dp

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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

    return dp[n][m];
}

int canYouMake(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();

    int a = solve(n, m, s1, s2);
    //  cout<<a<<endl;
    return (n - a) + (m - a);
}

// Tab
// dp[i][j] ==> till index [i][j] longest palindromic subsequence
int solve(int n, int m, string &ptr, string &str)
{

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // Base condn already satisfied while declaring dp

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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

    return prev[m];
}

int canYouMake(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();

    int a = solve(n, m, s1, s2);
    //  cout<<a<<endl;
    return (n - a) + (m - a);
}