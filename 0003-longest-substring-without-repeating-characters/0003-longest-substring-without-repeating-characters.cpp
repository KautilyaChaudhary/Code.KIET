class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
       int left = 0;
       unordered_map<char,bool> data;
       int result = 0;

       for(int right=0;right<s.size();++right)
       {
           while(data.find(s[right]) != data.end())
           {
               data.erase(s[left]);
               left++;
           }
           data[s[right]] = true;
           result = max(result,right - left + 1);
       }

       return result;
    }
};