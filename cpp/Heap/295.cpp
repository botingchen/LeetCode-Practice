class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> MaxHeap;
    priority_queue<int> MinHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        MinHeap.push(num);
        if(MinHeap.size() != 0 && MaxHeap.size() != 0 && MinHeap.top() > MaxHeap.top()){
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
        }
        if(((int)MaxHeap.size() - (int)MinHeap.size()) > 1){
            MinHeap.push(MaxHeap.top());
            MaxHeap.pop();
        }

        if(((int)MinHeap.size() - (int)MaxHeap.size()) > 1){
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
        }
        
    }
    
    double findMedian() {
        if(MinHeap.size() > MaxHeap.size()) return MinHeap.top();
        else if(MaxHeap.size() > MinHeap.size()) return MaxHeap.top();
        return (double)(MinHeap.top() + MaxHeap.top()) / (double) 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */