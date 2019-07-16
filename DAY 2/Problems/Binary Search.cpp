
// https://www.interviewbit.com/problems/matrix-median/

int Solution::findMedian(vector<vector<int> > &A) {
    
    int n = A.size(), m = 0;
    if(n != 0) m = A[0].size();
    int pos = (n * m) / 2 + 1;
    
    int low = 0, high = INT_MAX, ans = -1;
    while(low < high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt +=  upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin(); 
            
        if(cnt >= pos) ans = high = mid;
        else low = mid + 1;
    }

    return ans;
    
}
