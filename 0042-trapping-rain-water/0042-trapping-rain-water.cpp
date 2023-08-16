class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left; //maximum from left
        vector<int> right(height.size(), 0); //maximum from right
        int maxi = INT_MIN;
        for(auto it:height){
            maxi = max(maxi, it);
            left.push_back(maxi);
        }
        int n = height.size();
        maxi = INT_MIN;
        for(int i = n - 1;i >= 0;i-- ){
            maxi = max(maxi, height[i]);
            right[i] = maxi;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += (min(left[i], right[i]) - height[i]); //formula
        }
        return ans;
    }
};