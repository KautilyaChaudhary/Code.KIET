class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r = m.size();
        int c = m[0].size();
        
        int s = 0;
        int end = r*c-1;
        int mid = s +(end-s)/2;

        while(s<=end){
            int e = m[mid/c][mid%c];
            if(e == t){
                return 1;
            }
            if(e < t){
                s = mid+1;
            }
            else{
                end = mid-1;
                 
            }
            mid = s +(end-s)/2;
        }
        return 0; 
    }
};