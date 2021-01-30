/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {

    // Use 2 maps
    // One to map new nodes to orignal nodes
    // Other to map original nodes to the new nodes

    unordered_map<RandomListNode*, RandomListNode*> map;
    unordered_map<RandomListNode*, RandomListNode*> map2;
    RandomListNode* head = A;
    RandomListNode* newHead, *B, *prev = NULL;

    // Corner case

    if (A == NULL) {
        return NULL;
    }

    // Create a copy of the nodes and assign correct pointers
    // Also store the values in the 2 maps

    while (A) {
        newHead = new RandomListNode(A -> label);
        if (prev) {
            prev -> next = newHead;
        } else {
            B = newHead;
        }
        prev = newHead;
        map[newHead] = A;
        map2[A] = newHead;
        A = A -> next;
    }
    newHead = B;

    // Map random pointers of the new nodes in 2 steps:
    // 1) Point new node to the original node
    // 2) Map random pointer of the original node to the new node

    while (newHead) {
        newHead -> random = map2[map[newHead] -> random];
        newHead = newHead -> next;
    }
    return B;
}
