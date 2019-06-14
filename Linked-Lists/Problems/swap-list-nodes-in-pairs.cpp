/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *head = A;
    ListNode *prev = NULL;
    ListNode* pre = NULL;
    ListNode *next = NULL;
    ListNode *cur = A;

    // Swap nodes in pairs by keeping track of prev and next nodess

    while (cur && cur -> next) {
        next = cur -> next;
        cur -> next = next -> next;
        ListNode *temp = next -> next;
        next -> next = cur;
        if (pre) {
            pre -> next = next;
            pre = cur;
        } else {
            head = next;
            pre = cur;
        }
        cur = temp;
    }
    
    return head;
}
