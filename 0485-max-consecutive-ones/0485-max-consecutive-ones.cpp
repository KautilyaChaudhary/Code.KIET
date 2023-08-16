class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int previous=0;
      int current=0;
      for(int i=0;i<nums.size();i++)
      {
          if(nums[i]==0)
          {
              previous=max(current,previous);
              current=0;
          }
         else current++;
      }
      previous=max(current,previous);//covering the case maximum consecutive ones are in last;
      return previous;
    }
};