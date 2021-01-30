/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode * head = A;
    int length = 0;

    // Find length of the lists

    while (A) {
        length ++;
        A = A -> next;
    }
    if (length == 1) {
        return head;
    }

    // Set rotation length and point end node to the beginning and prev to NULL for rotating the list

    B = B % length;
    A = head;
    if (B == 0) {
        return A;
    }
    ListNode *prev = NULL;
    for (int i = 0; i < length - B; i ++) {
        prev = A;
        A = A -> next;
    }
    prev -> next = NULL;
    ListNode *C = A;
    while (C -> next != NULL) {
        C = C -> next;
    }
    C -> next = head;
    return A;
}
