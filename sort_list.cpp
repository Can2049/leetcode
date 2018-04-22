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
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        int num = 0;
        ListNode *cur = head;
        while (cur)
        {
            num++;
            cur = cur->next;
        }

        //buttom-up
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *left, *right, *tail;
        for (int step = 1; step < num; step *= 2)
        {
            //show(dummy.next);
            tail = &dummy;
            cur = dummy.next;
            while (cur)
            {
                left = cur;
                //cout << "l:" << left->val << endl;
                right = split(left, step);
                //cout << "r:" << right->val << endl;
                cur = split(right, step);
                //cout<<"c:"<<cur->val<<endl;
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }

  private:
    //return next head of list
    ListNode *split(ListNode *head, int step)
    {
        show(head, "split-");
        for (int i = 1; i < step && head; i++)
        {
            head = head->next;
        }
        if (!head)
        {
            return NULL;
        }
        ListNode *second = head->next;
        head->next = NULL;
        return second;
    }

    //return tail of new list
    ListNode *merge(ListNode *a, ListNode *b, ListNode *head)
    {
        ListNode *cur = head;
        while (a && b)
        {
            if (a->val <= b->val)
            {
                cur->next = a;
                a = a->next;
            }
            else
            {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }

        cur->next = a ? a : b;

        while (cur->next)
            cur = cur->next;
        //show(head, "merge-");
        return cur;
    }

    void show(ListNode *head, string pre = "")
    {
        string title = pre + "show: ";
        cout << title;
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};