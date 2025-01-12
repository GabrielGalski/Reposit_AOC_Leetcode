/**
Leetcode 19
 * };
 */



#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            return head;
        }
        fast = fast->next;
    }

    if (fast == NULL) {
        return head->next;
    }

    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return head;
}