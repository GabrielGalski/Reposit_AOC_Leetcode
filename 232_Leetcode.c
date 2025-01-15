/*
232 Implement Queue using Stacks - Leetcode
*/

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
    int count; 
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* list = (MyQueue*)malloc(sizeof(MyQueue));
    list->front = NULL; 
    list->rear = NULL;
    list->count = 0;   
    return list;
}

void myQueuePush(MyQueue* obj, int x) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;  
    if (obj->rear == NULL) { 
        obj->front = newnode;
        obj->rear = newnode;
    } else { 
        obj->rear->next = newnode;
        obj->rear = newnode;
    }
    obj->count++; 
}

int myQueuePop(MyQueue* obj) {
    if (obj->front == NULL) { 
        return -1; }
    node* temp = obj->front;
    int data = temp->data;
    obj->front = obj->front->next;

    if (obj->front == NULL) { 
        obj->rear = NULL;
    }
    free(temp);
    obj->count--; 
    return data;
}

int myQueuePeek(MyQueue* obj) {
    if (obj->front == NULL) {
        return -1;
    }
    return obj->front->data;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->front == NULL;
}

void myQueueFree(MyQueue* obj) {
    while (obj->front != NULL) {
        node* temp = obj->front;
        obj->front = obj->front->next;
        free(temp);
    }
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
