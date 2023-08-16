class Solution {
public:
    int pivot(vector<int>& b){
        int a=b.size();
        int pivot=-1;
        for(int c=a-2;c>=0;c--){
            if(b[c]<b[c+1]) 
                return c;
        }
        return pivot;
    }
    void nextPermutation(vector<int>& nums) {
        int a=nums.size();
        int num=pivot(nums);
        if(num==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        reverse(nums.begin()+(num+1),nums.end());
        
        for(int c=num+1;c<a;c++){
            if(nums[c]>nums[num]){
                swap(nums[c],nums[num]);
                break;
            }
        }
    }
};