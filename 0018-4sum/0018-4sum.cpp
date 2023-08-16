class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        if(num.size()<4) return {};
        set<vector<int>>ans;
        long long int sum1,sum2;
        sort(num.begin(),num.end());
        for(int a=0;a<num.size()-3;a++)
        {
            for(int j=a+1;j<num.size()-2;j++)
            {
                sum1 = num[a]+num[j];
                int p = j+1; 
                int q = num.size()-1; 
                while(p<q)
                {
                    sum2 = num[p]+num[q];
                    if(sum1+sum2 == target)
                    {
                        ans.insert({num[a],num[j],num[p],num[q]});
                        p++;
                    }
                    else if(sum1+sum2 > target) q--;
                    else p++;
                }
            }
        }
        vector<vector<int>>final_ans(ans.begin(),ans.end());
        return final_ans;
    }
};