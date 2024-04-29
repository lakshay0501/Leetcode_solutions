
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {

        int XOR = 0;

        for (auto x : nums)
        {
            XOR ^= x;
        }

        // now check each bit of XOR and compare it with each bit of k

        int ans = 0;

        for (int i = 0; i < 32; i++)
        {

            int bitXor = (1 << i) & XOR;
            int bitK = (1 << i) & k;

            if (bitXor != bitK)
            {
                ans++;
            }
        }

        return ans;
    }
};