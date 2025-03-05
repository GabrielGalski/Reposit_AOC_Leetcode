struct ListNode* mid(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = slow;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    return slow;
}

int Altura(struct TreeNode* root) {
    int iEsq, iDir;
    if (root == NULL)
        return 0;

    iEsq = Altura(root->left);
    iDir = Altura(root->right);

    if (iEsq > iDir)
        return iEsq + 1;
    else
        return iDir + 1;
}

int FB(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    return Altura(root->left) - Altura(root->right);
}

void RSE(struct TreeNode** root) {
    struct TreeNode* Aux;

    Aux = (*root)->right;
    (*root)->right = Aux->left;
    Aux->left = (*root);
    (*root) = Aux;
}

void RSD(struct TreeNode** root) {
    struct TreeNode* Aux;

    Aux = (*root)->left;
    (*root)->left = Aux->right;
    Aux->right = (*root);
    (*root) = Aux;
}

int BalancaEsq(struct TreeNode** root) {
    int fbe = FB((*root)->left);
    if (fbe > 0) {
        RSD(root);
        return 1;
    }
    else if (fbe < 0) {
        /* rotação dupla direita */
        RSE(&((*root)->left));
        RSD(root);
        return 1;
    }
    return 0;
}

int BalancaDir(struct TreeNode** root) {
    int fbd = FB((*root)->right);
    if (fbd < 0) {
        RSE(root);
        return 1;
    }
    else if (fbd > 0) {
        /* rotação dupla esquerda */
        RSD(&((*root)->right));
        RSE(root);
        return 1;
    }
    return 0;
}

int Balanceamento(struct TreeNode** root) {
    int fb = FB(*root);
    if (fb > 1)
        return BalancaEsq(root);
    else if (fb < -1)
        return BalancaDir(root);
    else
        return 0;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL){ 
        return NULL; 
        }

    if (head->next == NULL) {
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = head->val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    struct ListNode* midNode = mid(head);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = midNode->val;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(midNode->next);

    Balanceamento(&root);

    return root;
}