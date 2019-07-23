


// https://www.interviewbit.com/problems/order-of-people-heights/

const int N = 5E5 + 10;
int tree[N];

void update(int k, int st, int en, int idx)
{
    if(st > en || st > idx || en < idx) return ;
    if(st == en && st == idx)
    {
        tree[k] = 1;
        return ;
    }
    
    int mid = (st + en) / 2;
    update(2 * k + 1, st, mid, idx);
    update(2 * k + 2, mid + 1, en, idx);
    
    tree[k] = tree[2 * k + 1] + tree[2 * k + 2];
    
}

int query(int k, int st, int en, int L, int R)
{
    if(st > en || L > R || st > R || L > en)
        return 0;
    
    if(st == L && en == R) return tree[k];
    
    int mid = (st + en) / 2;
    if(R <= mid) return query(2 * k + 1, st, mid, L, R);
    
    if(L > mid) return query(2 * k + 2, mid + 1, en, L, R);
    
    return query(2 * k + 1, st, mid, L, mid) + query(2 * k + 2, mid + 1, en, mid + 1, R);
}

int binary_search(int st, int en, int x)
{
   int low = st, high = en;
   
   while(low < high)
   {
       int mid = (low + high) / 2;
       int value = mid + 1 - query(0, st, en, 0, mid);
      
       if(value < x) 
            low = mid + 1;
        else
            high = mid;
   }
   
   return high;
    
}


vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    
    fill(tree, tree + N, 0);
    
    vector<pair<int, int> > v;
    for(int i = 0; i < A.size(); i++)
        v.push_back({A[i], B[i]});
    
    sort(v.begin(), v.end());
    
    vector<int> ans(v.size(), 0);
    
    for(int i = 0; i < v.size(); i++)
    {
        int idx = binary_search(0, v.size() - 1, v[i].second + 1);
        ans[idx] = v[i].first;
        update(0, 0, v.size() - 1, idx);
    }
    
    return ans;
}
