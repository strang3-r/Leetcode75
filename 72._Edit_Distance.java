// Problem Link
// https://leetcode.com/problems/edit-distance/


public class Solution {
    int[][] dp;
    
    public int minDistance(String word1, String word2) {
	dp = new int[word1.length()][word2.length()];
	    
        return minDistanceHelper(word1, word2, 0, 0);
    }
    
    private int minDistanceHelper(String word1, String word2, int index1, int index2) {
        if (index1 == word1.length()) return word2.length() - index2;
        if (index2 == word2.length()) return word1.length() - index1;
	    
	if (dp[index1][index2] > 0) return dp[index1][index2];
        
        int result;
        if (word1.charAt(index1) == word2.charAt(index2)) {
            result = minDistanceHelper(word1, word2, index1+1, index2+1);
        } else {
            // replace char
            result = 1 + minDistanceHelper(word1, word2, index1+1, index2+1);
            
            // delete char from word1
            result = Math.min(result, 1 + minDistanceHelper(word1, word2, index1+1, index2));
            
            // delete char from word2
            result = Math.min(result, 1 + minDistanceHelper(word1, word2, index1, index2+1));
        }
        
	dp[index1][index2] = result;
	return result;
    }
}
