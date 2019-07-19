
// https://www.interviewbit.com/problems/flip-array/

int rec(int idx, int sum, const vector<int> &A, vector<vector<int> > &dp)
{
    if(sum == 0) return 0;
    if(idx == A.size()) return -1;
    
    if(dp[idx][sum] != -2) return dp[idx][sum];
    
    int ans = rec(idx + 1, sum, A, dp);
    if(ans == -1) ans = INT_MAX;
    if(A[idx] <= sum)
    {
        int p = rec(idx + 1, sum - A[idx], A, dp);
        if(p != -1)
            ans = min(ans, p + 1);
    }
    
    if(ans == INT_MAX) 
        ans = -1;
        
    dp[idx][sum] = ans;
    return ans;
}

int Solution::solve(const vector<int> &A) {
    
    int n = A.size();
    if(n <= 1) return 0;
    int sum = 0;
    for(auto k : A)
        sum += k;
    sum /= 2;
    vector<vector<int> > dp(n, vector<int>(sum + 1, -2));
    
    for(int val = sum; val >= 0; val--)
    {
        int ans = rec(0, val, A, dp);
        if(ans != -1) return ans;
    }
}
