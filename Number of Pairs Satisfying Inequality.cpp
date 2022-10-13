// Problem: https://leetcode.com/contest/biweekly-contest-88/problems/number-of-pairs-satisfying-inequality/
// Author: vrintle
// Category: LeetCode Hard

/*

Problem statement
-----------------

You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
Return the number of pairs that satisfy the conditions.

*/

template<typename T>
class segtree {
	public:
	vector<T> t;
	int n;
	T def;
	function<T(T, T)> fx;
	void build(int _n, T _def, function<T(T, T)> _fx) {
		n = _n, def = _def, fx = _fx;
		t.assign(n * 2, def);
		for(int i = n - 1; i; i--) t[i] = fx(t[i * 2], t[i * 2 + 1]);
	}
	void build(vector<T>& a, T _def, function<T(T, T)> _fx) {
		n = a.size(), def = _def, fx = _fx;
		t.assign(n * 2, def);
		for(int i = 0; i < n; i++) t[i + n] = a[i];
		for(int i = n - 1; i; i--) t[i] = fx(t[i * 2], t[i * 2 + 1]);
	}
	void update(int i, T v) {
		for(t[i += n] += v; i > 1; ) {
			i /= 2;
			t[i] = fx(t[i * 2], t[i * 2 + 1]);
		}
	}
	// this query is made on [l, r)
	T query(int l, int r) {
		T lans = def, rans = def;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l % 2) lans = fx(lans, t[l++]);
			if(r % 2) rans = fx(t[--r], rans);
		}
		return fx(lans, rans);
	}
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size(), N = 1e5;
        vector<int> a(n);
        auto E = [&](int x) {
            return x + N / 2;
        };
        segtree<int> Sum;
        Sum.build(N, 0, [&](int x, int y) {
            return x + y;
        });
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            a[i] = nums1[i] - nums2[i];
            ans += Sum.query(0, E(a[i] + diff) + 1);
            Sum.update(E(a[i]), 1);
        }
        return ans;
    }
};
