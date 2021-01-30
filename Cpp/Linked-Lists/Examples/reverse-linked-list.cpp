/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    ListNode* head = A;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    ListNode* cur = A;

    // Reverse a Linked List by keeping track of prev and next nodes

    while (cur && cur -> next) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    cur -> next = prev;
    return cur;
}