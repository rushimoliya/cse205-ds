class MinStack {
public:
    class Node{
        public:
            int data;
            int min;
            Node* prev;
            Node* next;
        Node(int _data,int _min){
            data = _data;
            min = _min;
            prev = NULL;
            next = NULL;
        }
    };
    Node *head = new Node(INT_MAX,INT_MAX);
    Node *tail = new Node(INT_MAX,INT_MAX);
    MinStack() {
            head->next = tail;
            tail->prev = head;
    }
    void insertNode(int val,int min){
        Node *nn = new Node(val,min);
        nn->next = tail;
        nn->prev = tail->prev;
        tail->prev->next = nn;
        tail->prev = nn;
    }
    void push(int val) {
        if(head->next== tail){
            insertNode(val,val);
        }
        else{
            Node *t = tail->prev;
            if(val<=t->min){
                insertNode(val,val);
            }
            else{
                insertNode(val,t->min);
            }
        }
    }
    
    void pop() {
        Node* t = tail->prev->prev;
        t->next = tail;
        tail->prev = t;
    }
    
    int top() {
        Node* t = tail->prev;
        return t->data;
    }
    void printList(){
        Node* t = head->next;
        while(t!=tail){
            cout<<t->min<<" ";
            t = t->next;
        }
        cout<<endl;
    }
    int getMin() {
        // printList();
        Node* t = tail->prev;
        return t->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */