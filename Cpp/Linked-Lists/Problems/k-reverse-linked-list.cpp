ListNode* Solution::reverseList(ListNode* A, int B) {

    // Corner case

    if (B == 1) {
        return A;
    }
    ListNode* head = A;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    ListNode* cur = A;
    ListNode* prevReal = cur;

    // Get k reverse Linked List by using Recursion

        for (int i = 0; i < B && cur; i ++) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        if (prevReal) {
            prevReal -> next = reverseList(cur, B);   
        }
    return prev;
}
