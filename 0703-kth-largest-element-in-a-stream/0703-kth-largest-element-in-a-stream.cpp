class KthLargest {
public:
    int ind;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        int i;
        ind = k;
        for(i=0 ; i<nums.size() ; i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>ind)
            pq.pop();
        return pq.top();
    }
};