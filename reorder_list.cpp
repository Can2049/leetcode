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
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return;
        }

        ListNode dummy(-1);
        dummy.next = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse right part
        ListNode *cur = slow->next;
        slow->next = NULL;
        ListNode rightPre(-1);
        rightPre.next = cur;
        ListNode *nex = cur->next;
        while (cur && cur->next)
        {
            nex = cur->next;
            cur->next = nex->next;
            nex->next = rightPre.next;
            rightPre.next = nex;
        }
        //apend
        cur = head;
        ListNode *right = rightPre.next;
        while (cur && right)
        {
            nex = cur->next;
            cur->next = right;
            right = right->next;
            cur->next->next = nex;
        }
    }

  private:
    void show(ListNode *a)
    {
        cout << "show: ";
        while (a)
        {
            cout << a->val << " ";
            a = a->next;
        }
        cout << endl;
    }
};