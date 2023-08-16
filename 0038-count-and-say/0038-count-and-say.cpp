class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string s=countAndSay(n-1);

        //say how to say it
        int freq=1;
        string ans="";
        char ch=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i] == ch){
                freq++;
            }else{
                ans+=to_string(freq);
                ans+=ch;
                freq=1;
                ch=s[i];
            }
        }
        ans+=to_string(freq);
        ans+=ch;
        return ans;
    }
};