/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://www.interviewbit.com/problems/recover-binary-search-tree/
 
#define T TreeNode 
T *pre, *mn_element;
void Find(T *root)
{
    if(root == NULL) return ;
    if(root->left == NULL && pre == NULL)
    {
        pre = root;
        Find(root->right);
        return ;
    }
    Find(root->left);
    if(pre->val > root->val && mn_element == NULL)
        mn_element = root;
    else if(mn_element == NULL)
        pre = root;
    else if(mn_element != NULL)
    {
        if(root->val < mn_element->val)
            mn_element = root;
    }
    Find(root->right);
}

vector<int> Solution::recoverTree(TreeNode* A) {
    pre = mn_element = NULL;
    Find(A);
    vector<int> answer;
    answer.push_back(mn_element->val);
    answer.push_back(pre->val);
    return answer;
}
