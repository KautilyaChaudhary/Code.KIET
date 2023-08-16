class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>v(n1+n2);
        int i =0; 
        int j = 0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                v[i+j]= nums1[i];
                i++;
            }
            else{
                v[i+j]=nums2[j];
                j++;
            }
        }
        //in case the array gets exhausted
         while (i < nums1.size()) {
            v[i + j] = nums1[i];
            i++;
        }
        while (j < nums2.size()) {
            v[i + j] = nums2[j];
            j++;
        }
 if(v.size() % 2 == 1) 
 return v[v.size() / 2];
 else 
 return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
    }
};