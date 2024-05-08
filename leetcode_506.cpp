class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {

        priority_queue<int> pq;

        for (auto x : score)
        {
            pq.push(x);
        }

        unordered_map<int, int> m;

        int rank = 1;

        while (pq.size() > 0)
        {
            m[pq.top()] = rank++;
            pq.pop();
        }

        vector<string> ans;
        for (int i = 0; i < score.size(); i++)
        {
            int rank = m[score[i]];

            if (rank == 1)
            {
                ans.push_back("Gold Medal");
            }
            else if (rank == 2)
            {
                ans.push_back("Silver Medal");
            }
            else if (rank == 3)
            {
                ans.push_back("Bronze Medal");
            }
            else
            {
                ans.push_back(to_string(rank));
            }
        }

        return ans;
    }
};