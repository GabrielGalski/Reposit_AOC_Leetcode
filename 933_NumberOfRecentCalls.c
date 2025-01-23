typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct {
    node* top;
    int limit;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->top = NULL;
    obj->limit = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = t;
    newnode->next = obj->top;
    obj->top = newnode;
    obj->limit++;
    node* current = obj->top;
    node* prev = NULL;
    while (current != NULL && current->data >= t - 3000) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        if (prev != NULL) {
            prev->next = NULL;
        }

        while (current != NULL) {
            node* temp = current;
            current = current->next;
            free(temp);
            obj->limit--;
        }
    }

    return obj->limit;
}

void recentCounterFree(RecentCounter* obj) { 
    free(obj); 
    }

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/