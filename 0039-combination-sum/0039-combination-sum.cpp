class Solution {
    void helper(vector<int>& candidates, int target,
                vector<int>& sum, vector<vector<int>>& comb, int start) {
        if (target == 0) {
            comb.push_back(sum);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                sum.push_back(candidates[i]);
                helper(candidates, target - candidates[i], sum, comb, i);
                sum.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> comb;
        vector<int> sum;
        helper(candidates, target, sum, comb, 0);
        return comb;
    }
};