class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        vector<int>temp;
        int fact=1;
        for(int i=1;i<n;i++){
              fact*=i;
              temp.push_back(i);
        }
        k=k-1;//for making zero base indexing
        temp.push_back(n);
        while(true){
          ans+=to_string(temp[k/fact]);
          temp.erase(temp.begin()+k/fact); //time complexity for erase is O(n)
          if(temp.size()==0) break;
          k%=fact;
          fact/=temp.size();
        }
        return ans;
    }
};