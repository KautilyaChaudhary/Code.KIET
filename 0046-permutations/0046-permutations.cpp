class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums,vector<int>&vis,vector<int>&s)
    {
            if(s.size()==nums.size())
            {
                ans.push_back(s);return ;
            }
            
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]==-1)
            {
                vis[i]=1;
                s.push_back(nums[i]);
                solve(nums,vis,s);
                vis[i]=-1;
                s.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>vis(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++)
        {
            vis[i]=1;
            vector<int>s;
            s.push_back(nums[i]);
            solve(nums,vis,s);
            vis[i]=-1;
            s.pop_back();
        }
        return ans;
    }
};