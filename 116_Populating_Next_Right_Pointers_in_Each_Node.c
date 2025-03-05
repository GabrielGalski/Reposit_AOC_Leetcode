/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

 struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node* curr = root;

    while (curr->left != NULL) {
        struct Node* pLeft = curr;
        struct Node* pRight = curr;

        while (pLeft != NULL) {
            pLeft->left->next = pLeft->right;

            if (pLeft->next != NULL) {
                pLeft->right->next = pLeft->next->left;
            }
            pLeft = pLeft->next;
        }
        curr = curr->left;
    }

    return root;
}
