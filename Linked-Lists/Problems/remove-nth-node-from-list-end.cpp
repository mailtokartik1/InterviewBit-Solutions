/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int length = 0;
    ListNode *head = A;

    // Find the length of the list

    while (A != NULL) {
        length ++;
        A =  A -> next;
    }
    A = head;

    // Corner case

    if (B >= length) {
        return A -> next;
    }

    // (N - k)th from the Front = Nth Node from the End

    for (int i = 0; i < length - B - 1; i ++) {
        A = A -> next;
    }
    if (A -> next != NULL) {
        A -> next = A -> next -> next;
    } else {
        A = A -> next;
    }
    if (length == 1) {
        return A;
    }
    return head;
}
