class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int a,b,m=matrix.size(),n=matrix[0].size();
        vector<int> row,column;
        for(a=0;a<m;a++){
            for(b=0;b<n;b++){
                if(matrix[a][b]==0){
                    if(row.size()<1 || (row.size()>=1 && row[row.size()-1]!=a) )
                      row.push_back(a);

                          if(column.size()<1 || (column.size()>=1 && column[column.size()-1]!=b) )
                     {column.push_back(b);}
                      
                }
            }
        }

        for(a=0;a<row.size();a++){

              for(b=0;b<n;b++){
                  matrix[row[a]][b]=0;
              }
        }
         for(a=0;a<column.size();a++){
              for(b=0;b<m;b++){
                  matrix[b][column[a]]=0;
              }
        }
         
    }
};