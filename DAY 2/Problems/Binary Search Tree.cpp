
// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void find_kthsmallest(TreeNode* root, int &k, int &ans)
{
    if(root == NULL) return;
    find_kthsmallest(root->left, k, ans);
    if(k == 0) return ;
    k--;
    if(k == 0) 
    { 
        ans = root->val;
        return ;
        
    }
    find_kthsmallest(root->right, k, ans);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    int ans = 0;
    find_kthsmallest(A, B, ans);
    return ans;
}
