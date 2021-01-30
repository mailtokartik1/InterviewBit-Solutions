/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    int length = 0;
    ListNode *head = A;

    // Find the length of the Linked List

    while (A) {
        length ++;
        A = A -> next;
    }
    A = head;

    // Determine where to reverse the Linked List

    ListNode *B = head;
    if (length % 2 == 1) {
        for (int i = 0; i < length / 2 + 1; i ++) {
            B = B -> next;
        }
    } else {
        for (int i = 0; i < length / 2; i ++) {
            B = B -> next;
        }
    }
    ListNode *prev = NULL;
    ListNode *cur = B;
    ListNode *next;
    while (cur) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }

    // Compare the values from start of the first half and end of the second reversed half of the Linked List

    while (prev) {
        if (prev -> val == head -> val) {
            prev = prev -> next;
            head = head -> next;
        } else {
            return 0;
        }
    }
    return 1;
}
