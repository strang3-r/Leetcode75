// Problem link
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

// Bottom-Up DP
// After you figure out top-down DP, it's easy to convert it to bottom-up solution. The only trick here is to move i backward. This ensures that smaller cuts are processed before calculating min cost for the larger ones. It happens this way naturally in the recursive solution.

public int minCost(int n, int[] cuts) {
    var c = new ArrayList<Integer>();
    for (int cut : cuts)
        c.add(cut);
    c.addAll(Arrays.asList(0, n));
    Collections.sort(c);
    int[][] dp = new int[c.size()][c.size()];
    for (int i = c.size() - 1; i >= 0; --i)
        for (int j = i + 1; j < c.size(); ++j) {
            for (int k = i + 1; k < j; ++k)
                dp[i][j] = Math.min(dp[i][j] == 0 ? Integer.MAX_VALUE : dp[i][j],
                    c.get(j) - c.get(i) + dp[i][k] + dp[k][j]);
        }
    return dp[0][c.size() - 1];    
}
