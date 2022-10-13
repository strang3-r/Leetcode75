template <class T>
class SegmentTree{
private:
    int n;
    vector<T> segtree;
public:
    SegmentTree(int n){
        this->n = n;
        segtree.resize(4 * n + 1);
    }
    T op(T x, T y){
        return max(x, y);
    }
    void updateVal(int x, int l, int r, int idx, T val){
        if (l > idx or r < idx)
            return;
        if (l == r)
        {
            segtree[x] = val;
            return;
        }
        int mid = (l + r) / 2LL;
        updateVal(2 * x, l, mid, idx, val);
        updateVal(2 * x + 1, mid + 1, r, idx, val);
        segtree[x] = op(segtree[2 * x], segtree[2 * x + 1]);
    }
    void update(int idx, T val){
        updateVal(1, 1, n, idx, val);
    }
    T cal(int x, int l, int r, int L, int R){
        if (L <= l and R >= r)
            return segtree[x];
        if (L > r or R < l)
            return 0;
        int mid = (l + r) / 2LL;
        return op(cal(2 * x, l, mid, L, R), cal(2 * x + 1, mid + 1, r, L, R));
    }
    T query(int l, int r){
        return l > r ? 0 : cal(1, 1, n, l, r);
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        const int M = 1e5 + 1;
        SegmentTree<int> dp(M);
        for (auto &e : nums)
        {
            int x = dp.query(e - k, e - 1) + 1;
            int y = dp.query(e, e);
            if (y < x)
                dp.update(e, x);
        }
        return dp.query(1, M);
    }
};
