class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int ind = m + n - 1, i = m - 1, j = n - 1;
        while(i >= 0 && j >= 0) {
            if(a[i] >= b[j]) a[ind--] = a[i--];
            else a[ind--] = b[j--];
        }
        while(i >= 0) a[ind--] = a[i--];
        while(j >= 0) a[ind--] = b[j--];
    }
};