class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        for(int a=0;a<n/2;a++){
            for(int j=a;j<n-a-1;j++){
                int row=a,col=j;
                int prevR=n-1-col,prevC=row;
                int temp= m[a][j];
                while(prevR!=a || prevC!=j){
                    m[row][col]=m[prevR][prevC];
                    row=prevR;
                    col=prevC;
                    prevR=n-1-col;
                    prevC=row;
                }
                m[row][col]=temp;
            }
        }    
    }
};

