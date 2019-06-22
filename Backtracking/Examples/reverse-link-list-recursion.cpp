/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* cur, ListNode* prev) {

    // Corner case

    if (cur == NULL) {
        return prev;
    }

    // Reverse a linked list just like when iterating it

    ListNode* next = cur -> next;
    cur -> next = prev;
    prev = cur;
    cur = next;
    return reverse(cur, prev);
}
ListNode* Solution::reverseList(ListNode* A) {

    // Corner case

    if (A == NULL || A -> next == NULL) {
        return A; 
    }
    return reverse(A, NULL);
}
