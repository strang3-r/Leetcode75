class Solution {
public:
    int hIndex(vector<int>& citations) {
        const auto n = citations.size();
        vector<int> count(n + 1, 0);
        for (const auto& x : citations) {
            // Put all x >= n in the same bucket.
            if (x >= n) {
                ++count[n];
            } else {
                ++count[x];
            }
        }

        int h = 0;
        for (int i = n; i >= 0; --i) {
            h += count[i];
            if (h >= i) {
                return i;
            }
        }
        return h;
    }
};


// Time complexity:  O(n)
// Space complexity: O(n)
