/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {

if(head == NULL){
    return true;
}

if(head->next == NULL){
    return true;
}

int count =0;

struct ListNode* curr = head;

while(curr != NULL){
    count++;
    curr = curr->next;
}

int* index = (int *)malloc(sizeof(int) * count);
curr = head;

for(int i=0; i<count;i++){
    index[i] = curr->val;
    curr = curr->next;
}

for (int i = 0; i < count/2; i++) {
        if (index[i] != index[count - 1 - i]) {
            free(index);
            return false; 
        }
    }
    free(index);
    return true; 
}