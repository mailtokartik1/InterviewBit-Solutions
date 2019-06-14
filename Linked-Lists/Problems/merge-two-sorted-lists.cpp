/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *C, *D;
    bool isFirst = true;

    // Compare the 2 pointers to the lists and merge them by moving the pointer with smaller value

    while (A != NULL && B != NULL) {
        if (A -> val <= B -> val) {
            if (isFirst) {
                C = new ListNode(A -> val);
                D = C;
                isFirst = false;
            } else {
                C -> next = new ListNode(A -> val);
                C = C -> next;
            }
            A = A -> next;
        } else {
            if (isFirst) {
                C = new ListNode(B -> val);
                D = C;
                isFirst = false;
            } else {
                C -> next = new ListNode(B -> val);
                C = C -> next;
            }
            B = B -> next;
        }
    }

    // Append non null list to the end of the list

    if (A == NULL && B == NULL) {
        return D;
    } else if (B == NULL) {
        while (A != NULL) {
            C -> next = new ListNode(A -> val);
            C = C -> next;
            A = A -> next;
        }
    } else if (A == NULL) {
        while (B != NULL) {
            C -> next = new ListNode(B -> val);
            C = C -> next;
            B = B -> next;
        }
    }
    return D;
}
