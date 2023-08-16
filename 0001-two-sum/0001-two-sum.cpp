class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a; 
        unordered_map<int,int> store;
        int n = nums.size();  
        int req;  

        for(int i =0; i<n;i++){
            req = target-nums[i];  
            if(store.find(req) != store.end()){  
                a.push_back(store[req]); 
                a.push_back(i);  
            }
            store[nums[i]]=i;
        }
        return a;
        
    }
    int main(){
        return 0;
    }
};