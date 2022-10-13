class Solution {
public:
    int minimizeXor(int num2, int num1) {
        int g = __builtin_popcount(num1);
        int ans = num2;
        map<int, int> a;
        for (int i = 0; i <= 30; i++)
            if ((num2 >> i) & 1)
                a[i] = 1;
        if (g <= a.size()){
            g = a.size() - g;
            for (auto &e : a){
                if (!g)
                    break;
                --g;
                ans -= (1 << e.first);
            }
            return ans;
        }
        g -= a.size();
        for (int i = 0; g > 0 and i <= 30; i++){
            if (!a[i]){
                --g;
                ans += (1 << i);
            }
        }
        return ans;
  }
  /*
  Solution to Miniminze XOR (https://leetcode.com/contest/weekly-contest-313/problems/minimize-xor/)
  */
