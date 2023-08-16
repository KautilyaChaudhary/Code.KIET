class Solution {
public:
    vector<int> majorityElement(vector<int>& num) {
        
        int n = num.size();
        if(n<=1)
            return num;
        
        int times = n/3;
        unordered_map<int,int> count;
        vector<int> a;

        for(int b=0;b<num.size();b++)
            count[num[b]]++;
        
        for(auto node: count)
        {
            if(count[node.first]>times)
                a.push_back(node.first);
        }
        return a;
    }
};