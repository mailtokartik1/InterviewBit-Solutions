/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* head = A;

    // Removing duplicates by comparing adjacent elements

    while (A -> next != NULL) {
        if (A -> val == A -> next -> val) {
            ListNode* B = A -> next;
            while (B -> val == A -> val && B -> next != NULL) {
                B = B -> next;
            }
            if (B -> val == A -> val) {
                A -> next = NULL;
                break;
            } else {
                A -> next = B;
            }
        }
        A = A -> next;
    }
    return head;
}