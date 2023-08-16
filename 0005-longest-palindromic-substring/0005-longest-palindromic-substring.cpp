class Solution {
public:  

   void findStrings(string &ans,string s , int i , int j  ){
    
       while(i>=0 && j<=s.length()&& s[i]==s[j]){
              int maxi = 0;
               string a =(s.substr(i,j-i+1) );
            
              if( ans.length()<a.length()){
                ans = a;
              }
               i--;
               j++;
           }
   }

      string longestPalindrome(string s) {
       string ans;
       int i =0;
          //    odd
       for(int i =0;i<s.size();i++){
             findStrings(ans,s,i,i);
       }
          //    even
       for(int i =0;i<s.size();i++){
              findStrings(ans,s,i,i+1);
    }

       return ans;

        
    }
};