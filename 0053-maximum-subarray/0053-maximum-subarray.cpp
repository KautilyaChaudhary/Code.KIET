class Solution {
public:
    int maxSubArray(vector<int>& n) {
       int s=0;
       int m=n[0];
       for(int a=0;a<n.size();a++){
           s+=n[a];
           m=max(s,m);
            if(s<0){
               s=0;
           }

       }
      
       return m;
    }
};