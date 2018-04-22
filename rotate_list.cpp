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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k <= 0)
        {
            return head;
        }

        int length = 0;
        ListNode *cur = head;
        while (cur)
        {
            length++;
            cur = cur->next;
        }
        if (length <= k)
        {
            return head;
        }
        ListNode dummy(-1);
        dummy.next = head;
        cur = head;
        for (int i = 1; i < length - k - 1; i++) //move to previous node
        {
            cur = cur->next;
        }
        dummy.next = cur->next;
        cur->next = NULL;
        cur = dummy.next;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = head;
        return dummy.next;
    }
};