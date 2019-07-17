
// https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();
    if(n == 0) return -1;
    
    int min_distance[n], max_distance[n];
    
    min_distance[0] = A[0];
    for(int i = 1; i < n; i++)
        min_distance[i] = min(min_distance[i-1], A[i]);
        
    max_distance[n-1] = A[n-1];
    for(int i = (n - 2); i >= 0; i--)
        max_distance[i] = max(max_distance[i+1], A[i]);
        
    int i = 0, j = 0, ans = -1;
    while(i < n && j < n)
    {
        if(min_distance[i] <= max_distance[j])
            ans = max(ans, (j++ - i));
        else
            i++;
    }
    
    return ans;
}
