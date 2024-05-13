//store a "min" variable and update every push
class MinStack {
public:
    MinStack() {
        cur = new Node(0, INT_MAX, nullptr);
    }
    
    void push(int val) {
        cur = new Node(val, min(val, cur->min), cur);
    }
    
    void pop() {
        cur = cur->prev;
    }
    
    int top() {
        return cur->val;
    }
    
    int getMin() {
        return cur->min;
    }
private:
    class Node{
    public:
        int val;
        int min;
        Node* prev;
        Node(int val, int min, Node* prev): val(val), min(min), prev(prev) {}
    };

    Node *cur;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */