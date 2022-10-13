class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int n = stamp.size(), total = 0;
        while (true) {
            bool isStamped = false;
            for (int size = n; size > 0; --size) {
                for (int i = 0; i <= n - size; ++i) {
                    string t = string(i, '*') + stamp.substr(i, size) + string(n - size - i, '*');
                    auto pos = target.find(t);
                    while (pos != string::npos) {
                        res.push_back(pos);
                        isStamped = true;
                        total += size;
                        fill(begin(target) + pos, begin(target) + pos + n, '*');
                        pos = target.find(t);
                    }
                }
            }
            if (!isStamped) break;
        }
        reverse(res.begin(), res.end());
        return total == target.size() ? res : vector<int>();
    }
};