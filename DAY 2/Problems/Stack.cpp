
// https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string A) {
    stack<string> st;
    string temp;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == ' ') 
        {
            temp = "";
            continue;
        }
        char k = A[i];
        if(k == '/')
        {
            if(temp.size() != 0)
            {
                if(temp == ".." && !st.empty())
                    st.pop();
                else if(temp[0] != '.')
                    st.push(temp);
            }
            temp = "";
        }
        else
            temp += k;
    }
    if(temp == ".." && !st.empty())
        st.pop();
    else if(temp.size() > 0 && temp[0] != '.')
        st.push(temp);
    
    string ans = "";
    while(!st.empty())
    {
        ans = "/" + st.top() + ans;
        st.pop();
    }
    if(ans.size() == 0) ans = "/";
    return ans;
}
