/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* curr = head->next;
    struct ListNode* prev = head;
    struct ListNode* temp = NULL;
    while (curr != NULL) {
        if (prev->val == curr->val) {
            temp = curr;
            prev->next = curr->next;
            free(temp);
            curr = prev->next;
        } 
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

