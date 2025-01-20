/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {

    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    struct ListNode* hA = headA;
    struct ListNode* hB = headB;

    int count1 = 0;
    int count2 = 0;

    while (hA != NULL) {
        count1++;
        hA = hA->next;
    }
    while (hB != NULL) {
        count2++;
        hB = hB->next;
    }

    hA = headA;
    hB = headB;

    if (count1 > count2) {
        int diff = count1 - count2;
        while (diff--) {
            hA = hA->next;
        }
    } else {
        int diff = count2 - count1;
        while (diff--) {
            hB = hB->next;
        }
    }

    while (hA != NULL && hB != NULL) {
        if (hA == hB) {
            return hA;
        }
        hA = hA->next;
        hB = hB->next;
    }
    return NULL;
}