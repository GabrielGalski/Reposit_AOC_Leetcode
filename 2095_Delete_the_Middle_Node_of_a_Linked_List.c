/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {

if(head == NULL || head->next== NULL){
    return NULL; }

struct ListNode* slow = head;
struct ListNode* fast = head;
struct ListNode* temp = NULL;

while(fast != NULL && fast->next != NULL){

    temp = slow;
    slow = slow->next;
    fast = fast->next->next;
}
temp->next = slow->next;

return head;
    
}