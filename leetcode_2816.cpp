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
    ListNode *reverseLL(ListNode *head)
    {

        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *currkanext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currkanext;
        }

        return prev;
    }

    ListNode *doubleIt(ListNode *head)
    {

        if (head == NULL)
        {
            return head;
        }

        ListNode *temp = head;

        temp = reverseLL(temp);

        ListNode *dummy = new ListNode(-1);

        ListNode *newhead = dummy;

        int carry = 0;
        while (temp != NULL)
        {
            int val = temp->val;

            val = val * 2;

            val += carry;

            int rem = val % 10;

            dummy->next = new ListNode(rem);

            dummy = dummy->next;

            int quo = val / 10;

            carry = quo;

            temp = temp->next;
        }

        if (carry > 0)
        {
            dummy->next = new ListNode(carry);
            dummy = dummy->next;
        }

        ListNode *fnode = reverseLL(newhead->next);

        return fnode;
    }
};