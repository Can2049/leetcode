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
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *new_head = NULL;
        while (head)
        {
            ListNode *cur = head;
            head = head->next;
            if (!new_head || cur->val < new_head->val)
            {
                //insert into beginning of new list
                cur->next = new_head;
                new_head = cur;
            }
            else
            {
                ListNode *p = new_head;
                while (p)
                {
                    if (!p->next || cur->val < p->next->val)
                    {
                        //insert into middle or end of new list
                        cur->next = p->next;
                        p->next = cur;
                        break;
                    }
                    p = p->next;
                }
            }
        }
        return new_head;
    }
};