// Solution to the Problem : Sort the matrix Diagonally
//https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        cout << n;
        int d = m*n-1;
        
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        
        
        for(int i = 0 ; i < m ; i++ ){
            vector<int> diag;
            int a = i;
            int b = 0;
            
            while(a<m&&b<n){
                
                diag.push_back(mat[a][b]);
                a++;
                b++;
                
            }
            sort(diag.begin(),diag.end());
             
            a = i;
            b = 0;
            int ind = 0;
            while(a<m && b<n){
                ans[a][b] = diag[ind];
                a++;
                b++;
                ind++;
                
            }
            
        }
        
        
          
        for(int i = 0 ; i < n ; i++ ){
            vector<int> diag;
            int a = 0;
            int b = i;
             
            while(b<n&&a<m){
                
                diag.push_back(mat[a][b]);
                a++;
                b++;
                
            }
            sort(diag.begin(),diag.end());
             
            a = 0;
            b = i;
            int ind = 0;
            while(b<n&&a<m){
                ans[a][b] = diag[ind];
                a++;
                b++;
                ind++;
                
            }
            
        }
         
        
        
        return ans;
        
    }
};