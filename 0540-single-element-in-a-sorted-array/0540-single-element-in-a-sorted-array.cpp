class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int e = n-1;

        ///////// Binary Search
        while(s < e){
            int mid = s + (e-s)/2;

            if(mid%2 == 1){
                mid--;
            }

            if(nums[mid] != nums[mid+1]){
                e = mid;
            } else {
                s = mid+2;
            }
        }

        return nums[s];
    }
};