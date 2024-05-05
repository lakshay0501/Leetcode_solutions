class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {

        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size() - 1;

        int b = 0;

        while (left <= right)
        {
            if (people[left] + people[right] <= limit)
            {
                b++;
                left++;
                right--;
            }
            else if (people[left] + people[right] > limit)
            {
                right--;
                b++;
            }
        }

        return b;
    }
};