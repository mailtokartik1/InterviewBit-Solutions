/**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
ListNode* Solution::reverseBetween(ListNode* A, int D, int C) {
    ListNode *head = A;
    ListNode *prev = NULL;
    ListNode *temp = A;
    int length = 0;
    
    // Find length of the list

    while (temp) {
        length ++;
        temp = temp -> next;
    }
    if (length == 1) {
        return A;
    }

    // Sort from index n to index m by keeping track of prev and next nodes

    for (int i = 0; i < D - 1; i ++) {
        prev = A;
        A = A -> next;
    }
    ListNode *B = A;
    for (int i = 0; i < C - D; i ++) {
        A = A -> next;
    }
    ListNode* next = A -> next;
    ListNode* pre = next;
    ListNode* realNext = NULL;
    ListNode* cur = B;
    for (int i = 0; i < C - D + 1; i ++) {
        realNext = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = realNext;
    }
    if (prev == NULL) {
        head = pre;
    } else {
        prev -> next = pre;
    }
    return head;
}

