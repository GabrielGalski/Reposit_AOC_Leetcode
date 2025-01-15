/*
225 Implement Stack using Queues - leetcode
*/

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct {
    node* top;  
    int limit;  
} MyStack;

MyStack* myStackCreate() {
    MyStack* list = (MyStack*)malloc(sizeof(MyStack));
    list->top = NULL;  
    list->limit = 0;   
    return list;
}

void myStackPush(MyStack* obj, int x) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = obj->top;  
    obj->top = newnode;        
    obj->limit++;              
}

int myStackPop(MyStack* obj) {
    node* temp = obj->top;     
    int val = temp->data;    
    obj->top = temp->next;     
    free(temp);                
    obj->limit--;
    return val;              
}

int myStackTop(MyStack* obj) {
    return obj->top->data;  
}

bool myStackEmpty(MyStack* obj) {
    return obj->top == NULL;
}

void myStackFree(MyStack* obj) {
    while (!myStackEmpty(obj)) {
        myStackPop(obj);  
    }
    free(obj);  
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */
