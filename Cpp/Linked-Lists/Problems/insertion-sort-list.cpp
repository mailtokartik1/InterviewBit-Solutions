/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Global variable used for checking of the new Element inserted at the beginning

bool isHead = false;

// Helper function to insert a node into the list

ListNode* insert(ListNode* head, ListNode* A, ListNode* B, ListNode* prev, ListNode* next, int count) {
    if (prev == NULL) {
        ListNode* temp = head;
        return NULL;
    }
    ListNode* pre = NULL;
    for (int i = 0; i < count; i ++) {
        if (B -> val >= A -> val) {
            if (pre == NULL) {
                head = A;
                A -> next = B;
                prev -> next = next;
                ListNode* temp = head;
                while (temp) {
                    temp = temp -> next;
                }
                isHead = true;
                return head;
            } else {
                pre -> next = A;    
            }
            A -> next = B;
            prev -> next = next;
            ListNode* temp = head;
            return B;
        }
        pre = B;
        B = B -> next;
    }
    return NULL;
}
ListNode* Solution::insertionSortList(ListNode* A) {
    isHead = false;
    ListNode* head = A;
    int length = 0;

    // Find the length of the list

    while (A) {
        length ++;
        A = A -> next;
    }
    A = head;
    ListNode* B = A;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    ListNode* cur = A;
    int count = -1;

    // Perform insertions in the list one by one

    while (cur) {
        isHead = false;
        count ++;
        next = cur -> next;
        ListNode* tempNode = insert(head, cur, B, prev, next, count);
        if (isHead) {
            head = tempNode;
            isHead = false;
        }
        if (tempNode == NULL) {
            prev = cur;
        }
        cur = next;
        B = head;
    }
    return head;
}
