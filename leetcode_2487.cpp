/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {

        vector<int> temp;

        ListNode *node = head;

        while (node != NULL)
        {
            temp.push_back(node->val);
            node = node->next;
        }

        // finding next greater element
        stack<int> st;

        int n = temp.size();

        vector<int> ans;

        for (int i = n - 1; i >= 0; i--)
        {

            while (st.size() > 0 && st.top() <= temp[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(temp[i]);
            }
            st.push(temp[i]);
        }

        reverse(ans.begin(), ans.end());

        // for(auto x : ans){
        //     cout<<x<<" ";
        // }

        ListNode *dummy = new ListNode(-1);

        ListNode *nhead = dummy;

        for (int i = 0; i < ans.size(); i++)
        {
            ListNode *nn = new ListNode(ans[i]);
            dummy->next = nn;
            dummy = dummy->next;
        }

        return nhead->next;
    }
};