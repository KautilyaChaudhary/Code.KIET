class Solution {
public:
    int minDistance(string s, string t) {
       int n1 = s.size();
        int n2 = t.size();
        vector<int> cur(n2 + 1, 0);
        for (int i = 0; i <= n2; i++)
        {
            cur[i] = i;
        }
        for (int i = 1; i <= n1; i++)
        {
            vector<int> prev(n2 + 1, 0);
            prev[0] = i;
            for (int j = 1; j <= n2; j++)
            {
                if (s[i-1] == t[j-1])
                    prev[j] = cur[ j - 1];
                else
                    prev[j] = 1 + min(prev[j - 1], min(cur[ j - 1], cur[j]));
            }
            cur = prev;
        }
        return cur[n2];
    }
};