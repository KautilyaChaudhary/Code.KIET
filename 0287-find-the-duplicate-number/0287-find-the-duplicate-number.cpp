class Solution {
public:
    int findDuplicate(vector<int>& n) {
        int f=n[0];
        int s=n[0];
        do{
            f=n[n[f]];
            s=n[s];
        }while(f!=s);
        s=n[0];
        while(s!=f){
            s=n[s];
            f=n[f];
        }
        return f;    }
};