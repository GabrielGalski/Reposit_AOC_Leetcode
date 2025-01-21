struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
    }
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    return head;
}
