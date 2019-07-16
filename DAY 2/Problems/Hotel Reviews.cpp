
// https://www.interviewbit.com/problems/hotel-reviews/

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    
    map<string, int> check;
    string temp;
    for(auto k : A)
    {
        if(k == '_')
        {
            check[temp] = 1;
            temp = "";
        }
        else 
            temp += k;
    }
    check[temp] = 1;
    
    int idx = 0;
    vector<pair<int, int> > v;
    for(auto s : B)
    {
        temp = "";
        int cnt = 0;
        for(auto k : s)
        {
            if(k == '_')
            {
                if(check.find(temp) != check.end()) 
                    cnt++;
                temp = "";
            }
            else 
                temp += k;
        }
        if(check.find(temp) != check.end())
            cnt++;
        v.push_back({cnt, idx++});
    }
    
    sort(v.begin(), v.end(), cmp);
    vector<int> ans;
    for(auto k : v)
        ans.push_back(k.second);
        
    return ans;
}
