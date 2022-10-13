class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        int i, n, val, x, y;
        n = a.size();
        x = a[1][0] - a[0][0];
        y = a[1][1] - a[0][1];
        for(i=0; i<n; i++) {
            if((a[i][1] - a[0][1]) * x != (a[i][0] - a[0][0]) * y) return 0;
        }
        return 1;
    }
};