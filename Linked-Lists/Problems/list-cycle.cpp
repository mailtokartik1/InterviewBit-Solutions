/**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
ListNode* Solution::detectCycle(ListNode* A) {

    // Alternate solution

    /*
    map<ListNode*, int> B;
    while (A) {
        if (B[A]) {
            return A;
        } else {
            B[A] = 1;
        }
        A = A -> next;
    }
    return NULL;
    */

    ListNode* slow = A;
    ListNode* fast = A;
    bool isCycle = false;

    // Use 2 pointers fast and slow where fast moves twice the pace of slow
    // Flloyd's Cycle Finding alogorithm

    while (fast && fast -> next) {
        fast = fast -> next;
        if (fast -> next) {
            slow = slow -> next;
            fast = fast -> next;
        } else break;
        if (slow == fast) {
            isCycle = true;
            break;
        }
    }
    if (isCycle) {
        slow = A;
        while (slow != fast) {
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    } else return NULL;
}

