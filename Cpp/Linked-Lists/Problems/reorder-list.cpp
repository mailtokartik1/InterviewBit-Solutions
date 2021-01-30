/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    ListNode* head = A;
    int length = 0;

    // Get length of the list

    while (A) {
        A = A -> next;
        length ++;
    }

    // Corner case

    if (length <= 2) {
        return head;   
    } 
    A = head;

    // Find the middle element for reversing the latter half
    
    ListNode* prev = NULL;
    if (length % 2 == 1) {
        for (int i = 0; i < length / 2 + 1; i ++) {
            prev = A;
            A = A -> next;
        }
    } else {
        for (int i = 0; i < length / 2; i ++) {
            prev = A;
            A = A -> next;
        }
    }

    // rotate the 2nd half of the list

    ListNode* next = NULL;
    ListNode* cur = A;
    ListNode* pre = NULL;
    while (cur && cur -> next) {
        next = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = next;
    }
    if (cur) {
        cur -> next = pre;
    }

    // Get the sequence by alternating nodes

    ListNode* tempNext;
    ListNode* tempNext2;
    ListNode* tempPre = NULL;
    ListNode* tempPre2 = NULL;
    bool toggle = false;
    ListNode* realHead = head;
    A = cur;
    if (length % 2 == 0) {
        while (head && head -> next && A && A -> next) {
            if (!toggle) {
                tempNext = head -> next;
                tempNext2 = A -> next;
                head -> next = A;
                head = tempNext;
                toggle = true;
            } else {
                tempNext = head -> next;
                tempNext2 = A -> next;
                A -> next = head;
                A = tempNext2;
                toggle = false;
            }
        }
        return realHead;
    } else {
        prev -> next = NULL;
        while (head && head -> next && A) {
            if (!toggle) {
                tempNext = head -> next;
                tempNext2 = A -> next;
                head -> next = A;
                head = tempNext;
                toggle = true;
            } else {
                tempNext = head -> next;
                tempNext2 = A -> next;
                A -> next = head;
                A = tempNext2;
                toggle = false;
            }
        }
        A -> next = prev;
        return realHead;
    }
}
