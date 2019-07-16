// https://www.interviewbit.com/problems/burst-balloons/

int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for(int len = 1; len <= n; len++)
    {
        for(int i = 0; (i + len - 1) < n; i++)
        {
            int j = i + len - 1;
            int answer = 0;
            for(int k = i; k <= j; k++)
            {
                int value = A[k];
                if((i - 1) >= 0) value *= A[i - 1];
                if((j + 1) < n) value *= A[j + 1];
                if(k > i) value += dp[i][k - 1];
                if(k < j) value += dp[k + 1][j];
                answer = max(answer, value);
            }
            dp[i][j] = answer;
        }
    }
    return dp[0][n-1];
}