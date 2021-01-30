/**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {

    // Get lengths of both the lists

    ListNode* headA = A;
    ListNode* headB = B;
    int length1 = 0, length2 = 0;
    while (B) {
        length2 ++;
        B = B -> next;
    }
    while (A) {
        length1 ++;
        A = A -> next;
    }
    A = headA;
    B = headB;

    // Compare both pointer values until at least one of the list ends

    if (length1 < length2) {
        for (int i = 0; i < length2 - length1; i ++) {
            B = B -> next;
        }
    } else if (length1 > length2) {
        for (int i = 0; i < length1 - length2; i ++) {
            A = A -> next;
        }
    }

    // Append the remaining part to the list

    while (A && B) {
        if (A != B) {
            A = A -> next;
            B = B -> next;
        } else {
            return A;
        }
    }
    return NULL;
}

