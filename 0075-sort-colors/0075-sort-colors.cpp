class Solution {
public:
    void sortColors(vector<int>& n) {
        int i = 0, j = 0, k = n.size() - 1;
        
        while (j <= k) {
            if (n[j] == 0) {
                swap(n[i], n[j]);
                i++;
                j++;
            }
            else if (n[j] == 1) {
                j++;
            }
            else if (n[j] == 2) {
                swap(n[j], n[k]);
                k--;
            }
        }
    }
};