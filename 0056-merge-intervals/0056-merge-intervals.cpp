class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inte) {
        vector<vector<int>>r;
    sort(inte.begin(), inte.end());
    for(int i = 0; i < inte.size(); i++)
    {
        if(r.empty() || r.back()[1] < inte  [i][0])
        {
            r.push_back(inte[i]);
        }
        else
        {
            r.back()[1]= max(r.back()[1], inte[i][1]);
        }
    }
    return r;
    }
};