class MyStack {
public://using a single Queue
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size=q.size();
       
        for(int i=0;i<size-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int res=q.front();
        q.pop(); return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};