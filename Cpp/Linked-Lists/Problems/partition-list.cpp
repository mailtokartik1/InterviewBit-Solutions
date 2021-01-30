/**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* head = A;
    ListNode* prev = NULL;

    // Find pointer where A -> val >= B

    while (A && A -> val < B) {
        prev = A;
        A = A -> next;
    }
    ListNode* tempHead = A;
    if (A == NULL) {
        return head;
    }
    A = tempHead -> next;
    if (A == NULL) {
        return head;
    }
    ListNode* next = NULL;
    ListNode* pre = tempHead;

    // Loop until the end of the list and swap the elements before A found above

    while (A) {
        if (A -> val < B) {
            next = A -> next;
            pre -> next = next;
            if (prev == NULL) {
                head = A;
            } else {
                prev -> next = A;
            }
            A -> next = tempHead;
            prev = A;
            A = next;
        } else {
            pre = A;
            A = A -> next;
        }
    }
    return head;
}

