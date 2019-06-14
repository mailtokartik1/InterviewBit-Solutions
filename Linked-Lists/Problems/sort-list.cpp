/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Helper function to merge 2 Linked Lists

ListNode* sortedMerge(ListNode* A, ListNode* B){
    if(A == NULL){
        return B;
    }
    if(B == NULL){
        return A;
    }
    
    ListNode* head = NULL;
    
    if(A -> val < B -> val) {
        head = A;
        A = A -> next;
    }
    else{
        head = B;
        B = B -> next;
    }
    
    ListNode* temp = head;
    
    while(A != NULL && B != NULL) {
        if(A -> val < B -> val) {
            temp -> next = A;
            A = A -> next;
        } else{
            temp -> next = B;
            B = B -> next;
        }
        temp = temp -> next;
    }
    
    if (A != NULL) {
        temp -> next = A;
    } else {
        temp -> next = B;
    }

    return head;
}
ListNode* Solution::sortList(ListNode* A) {
    ListNode* head = A;

    // Corner case
    
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode* start = A;
    ListNode* end = A -> next;

    // Split the list into 2 halves for mergeSort
    
    while (end != NULL && end -> next != NULL) {
        start = start -> next;
        end = (end -> next) -> next;
    }
    
    end = start -> next;
    start -> next = NULL;
    
    return sortedMerge(sortList(head), sortList(end)); 
}