#define ll long long
class Solution
{
public:
    long long countSubarrays(vector<int> &v, int minK, int maxK)
    {
        ll l = 0, r = 0, ans = 0, start = -1;
        multiset<ll> mn, mx;
        set<ll> stmn, stmx;
        for (ll i = 0; i < v.size(); i++)
        {
            if (v[i] < minK or v[i] > maxK)
            {
                while (l < i and !mn.empty() and !stmn.empty() and !stmx.empty())
                {
                    if (*mn.begin() == minK and -*mx.begin() == maxK)
                        ans += i - max(*stmn.begin(), *stmx.begin());
                    mn.erase(mn.find(v[l]));
                    mx.erase(mx.find(-v[l]));
                    l++;
                    while (!stmn.empty() and *stmn.begin() < l)
                        stmn.erase(stmn.begin());
                    while (!stmx.empty() and *stmx.begin() < l)
                        stmx.erase(stmx.begin());
                }
                l = i + 1;
                while (!stmn.empty() and *stmn.begin() < l)
                    stmn.erase(stmn.begin());
                while (!stmx.empty() and *stmx.begin() < l)
                    stmx.erase(stmx.begin());
                continue;
            }
            mn.insert(v[i]);
            mx.insert(-v[i]);
            if (v[i] == minK)
            {
                stmn.insert(i);
            }
            if (v[i] == maxK)
            {
                stmx.insert(i);
            }
        }
        while (l < v.size() and !mn.empty() and !stmn.empty() and !stmx.empty() and !stmn.empty())
        {
            if (*mn.begin() == minK and -*mx.begin() == maxK)
                ans += v.size() - max(*stmn.begin(), *stmx.begin());
            mn.erase(mn.find(v[l]));
            mx.erase(mx.find(-v[l]));
            l++;
            while (!stmn.empty() and *stmn.begin() < l)
                stmn.erase(stmn.begin());
            while (!stmx.empty() and *stmx.begin() < l)
                stmx.erase(stmx.begin());
        }
        return ans;
    }
};