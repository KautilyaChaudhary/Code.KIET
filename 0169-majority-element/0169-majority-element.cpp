class Solution {
public:
    int majorityElement(vector<int>& nums) {
        

        int answer=0;
        int element,counter=0;
    
        for(int i=0;i<nums.size();i++)
        {
            if(counter==0)
            {
                element=nums[i];
                counter=1;
            }
            else if(nums[i]==element)
                counter++;
            else
                counter--;
        }
        return element;
    }
};