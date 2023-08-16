class MedianFinder {
public:
    priority_queue<long> stream1; // max heap
    priority_queue<long, vector<long>, greater<long>> stream2; // min heap
    MedianFinder() {
        
    }
    void addNum(int num) {
        stream1.push(num);
        stream2.push(stream1.top());
        stream1.pop();
       
        if(stream1.size() < stream2.size()){
           
            stream1.push(stream2.top());
            stream2.pop();
        }
    }
    
    double findMedian() {
        if(stream1.size() == stream2.size()) return (stream1.top() + stream2.top())/2.0;
        else return stream1.top();
    }
};