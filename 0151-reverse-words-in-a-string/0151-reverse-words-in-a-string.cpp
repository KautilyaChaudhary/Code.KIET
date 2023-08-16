class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        vector<string> ans;
        string answer,temp;
        for(int i=0;i<s.length();i++) {
            if(s[i]!=' ') {
                temp+=s[i];
            }
            else if(temp.length()>0 && temp.size()>0) {
            ans.push_back(temp);
            temp="";
            }
        }

        for(int i=ans.size()-1;i>=0;i--) {
            if(i!=0) {
            answer+=ans[i];
            answer+=" ";
            }
            else
            answer+=ans[i];
        }
        return answer;
    }
};