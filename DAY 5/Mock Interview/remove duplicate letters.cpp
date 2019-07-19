

// https://www.interviewbit.com/problems/remove-duplicate-letters/

string Solution::solve(string A) {
    
    unordered_map<char, int> count, check;
    for(auto k : A) count[k]++;
    
    stack<char> st;

    for(auto k : A)
    {
        
        count[k]--;
        if(check.find(k) != check.end())
            continue;
            
        while((!st.empty() && (st.top() > k)) && (count[st.top()] > 0)) 
        {
            check.erase(st.top()); 
            st.pop();
        }
        
        check[k] = 1, st.push(k);
        
    }
    string ans;
    while(!st.empty()) ans += st.top(), st.pop();
    reverse(ans.begin(), ans.end());
    return ans;
}
