/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }

        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = pre->next;

        while (cur && cur->next)
        {
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;

            pre = cur;
            cur = cur->next;
        }
        return dummy.head;
    }
};