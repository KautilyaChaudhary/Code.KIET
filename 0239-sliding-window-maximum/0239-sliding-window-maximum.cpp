class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int j = 0, i = 0;
    multiset<int, greater<int>> s;
    vector<int> v;
    while (j < nums.size())
    {
        s.insert(nums[j]);
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            v.push_back(*(s.begin()));
            s.erase(s.find(nums[i]));
            i++, j++;
        }
    }
    return v;}
};