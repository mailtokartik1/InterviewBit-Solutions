/**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
ListNode* Solution::deleteDuplicates(ListNode* A) {

    // Removing duplicates by comparing adjacent elements and keeping track of previous pointer

    ListNode* head = A;
    ListNode *prev = NULL;
    while (A != NULL && A -> next != NULL) {
        //cout << "here" << A -> val;
        if (A -> val == A -> next -> val) {
            //cout << "here" << A -> val;
            ListNode *B = A -> next;
            //cout << B -> val;
            while (B != NULL && B -> val == A -> val) {
                B = B -> next;
            }
            if (B == NULL) {
                if (prev == NULL) {
                    return NULL;
                } else {
                    prev -> next = NULL;
                    return head;
                }
            } else {
                if (prev == NULL) {
                    head = B;
                    A = B;
                } else {
                    prev -> next = B;
                    A = B;
                }
                continue;
            }
        }
        prev = A;
        A = A -> next;
    }
    
    return head;
}

