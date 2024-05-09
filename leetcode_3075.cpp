#define ll long long
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        ll ans = 0;

        sort(happiness.rbegin(), happiness.rend());

        int itr = 0;
        while (itr < happiness.size() && k--)
        {
            ll val = happiness[itr] - itr;
            if (val > 0)
                ans += val;
            itr++;
        }

        return ans;
    }
};