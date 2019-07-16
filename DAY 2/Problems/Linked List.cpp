
// https://www.interviewbit.com/problems/palindrome-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int find_len(ListNode* A)
{
    int len = 0;
    while(A != NULL)
    {
        len++;
        A = A->next;
    }
    return len;
}
ListNode* reverse(ListNode* A)
{
    if(A->next == NULL) return A;
    ListNode *head, *current, *prev, *next;
    current = A;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int Solution::lPalin(ListNode* A) {
    int len = find_len(A);
    if(len <= 1) return 1;
    int req = len / 2, cnt = 0;
    ListNode *B = A, *prev = A;
    while(cnt < req)
    {
        cnt++;
        prev = B;
        B = B->next;
    }
    if(len & 1)
        B = B->next;
    
    prev->next = NULL;
    A = reverse(A);
    while(A != NULL)
    {
        if(B == NULL) return 0;
        if(A->val != B->val) return 0;
        A = A->next;
        B = B->next;
    }
    
    if(B != NULL) return 0;
    return 1;
    
}
