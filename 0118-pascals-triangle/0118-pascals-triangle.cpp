class Solution {
public:
     vector<int> getRow(int v) {
         long long a=1;
           vector<int> res(v + 1,1);
         for(int b=1;b<v;b++){
             a=a*(v+1-b)/b;
              res[b]=a;
         }
         return res; 
    }

    vector<vector<int>> generate(int vr) {
        
        vector<vector<int>>pas;
        for(int b=0;b<vr;b++){
            pas.push_back(getRow(b));
                         
        }
        return pas;
    }
};