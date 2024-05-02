class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        int maxi = -1e5;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0 && nums[i] > maxi)
            {
                if (m.count(-nums[i]) > 0)
                {
                    maxi = nums[i];
                }
            }
        }

        return maxi == -1e5 ? -1 : maxi;
    }
};