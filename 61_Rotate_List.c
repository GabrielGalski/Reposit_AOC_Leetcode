/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }

    struct ListNode* curr = head;
    int kSize = 1;
    while (curr->next != NULL) {
        curr = curr->next;
        kSize++;
    }
    curr->next = head;

    k = k % kSize; 
    int leng = kSize - k;
    if(k == 0){
        return head;
    }

    struct ListNode* end = head;
    for (int i = 1; i < leng; i++) { 
        end = end->next;
    }
    struct ListNode* newHead = end->next;

    end->next = NULL;

    return newHead;
}