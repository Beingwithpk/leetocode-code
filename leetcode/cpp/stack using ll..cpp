class Node{
    public:
    Node* next;
    int data;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedListStack {
    Node* topNode;
    int count;
public:
    LinkedListStack() {
        topNode=NULL;
        count=0;
    }
    
    void push(int x) {
        Node* newNode=new Node(x);
        newNode->next=topNode;
        topNode=newNode;
        count++;
    }
    
    int pop() {
        if(topNode==NULL){
            return -1;
        }
        Node* removedNode=topNode;
        int removedValue=removedNode->data;
        topNode=topNode->next;
        count--;
        return removedValue;
    }
    
    int top() {
    if(topNode==NULL){
            return -1;
        }
        return topNode->data; 
    }
    
    bool isEmpty() {
        return topNode == NULL;
    }
    int size() {
        return count;
    }
};