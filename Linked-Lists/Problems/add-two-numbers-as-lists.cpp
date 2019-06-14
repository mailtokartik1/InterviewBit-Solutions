/**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int C = 0;
    ListNode* head = A;
    ListNode *prev = NULL;

    // Corner cases

    if (A == NULL) {
        return B;
    } else if (B == NULL) {
        return A;
    }

    // Perform normal addition with sum and carry terems

    while (A && B) {
        int num = A -> val + B -> val + C;
        int val = num % 10;
        A -> val = val;
        C = num / 10;
        prev = A;
        A = A -> next;
        B = B -> next;
    }

    // Perform link handling on addition

    if (A == NULL && B == NULL) {
        if (C == 0) {
            return head;
        } else {
            prev -> next = new ListNode(C);
            return head;
        }
    } else if (A == NULL) {
        prev -> next = B;
        while (B) {
            int num = B -> val + C;
            int val = num % 10;
            B -> val = val;
            C = num / 10;
            prev = B;
            B = B -> next;
        }
        if (C == 0) {
            return head;
        } else {
            prev -> next = new ListNode(C);
            return head;
        }
        return head;
    } else if (B == NULL) {
        prev -> next = A;
        while (A) {
            int num = A -> val + C;
            int val = num % 10;
            A -> val = val;
            C = num / 10;
            prev = A;
            A = A -> next;
        }
        if (C == 0) {
            return head;
        } else {
            prev -> next = new ListNode(C);
            return head;
        }
        return head;
    }
    return head;
}

