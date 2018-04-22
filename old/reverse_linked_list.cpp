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
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }
        ListNode dummy(0);
        ListNode *pre_head = &dummy;
        pre_head->next = head;
        ListNode *cur = head;
        while (cur && cur->next)
        {
            ListNode *temp = cur->next;
            cur->next = cur->next->next;
            temp->next = head;
            pre_head->next = temp;
            head = temp;
        }
        return pre_head->next;
    }
};