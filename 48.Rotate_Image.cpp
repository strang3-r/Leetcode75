// Solution to the Problem : Rotate Image
// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0 ; i  < m ; i++){
            
            for(int j = i ; j < n ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
            
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n /2 ;j++){
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
        
    }
};