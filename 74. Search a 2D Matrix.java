class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (int r=0; r<matrix.length; r++){
            for (int c=0; c<matrix[r].length; c++){
                if (matrix[r][c]==target){
                    return true;
                }
                    
            }
        }
        return false;
    }
}
