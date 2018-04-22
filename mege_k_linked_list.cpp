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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;

        int last = lists.size() - 1;
        while (last)
        {
            int i = 0;
            int j = last;
            while (i < j)
            {
                lists[i] = sortMerge(lists[i], lists[j]);
                //cout << "val: " << lists[i]->val << endl;
                i++, j--;
                if (i >= j)
                    last = j;
            }
        }
        return lists[0];
    }

  private:
    ListNode *sortMerge(ListNode *a, ListNode *b)
    {
        /*  debug
        cout << "sort ";
        if (a)
            cout
                << "a:" << a->val << "\t";
        if (b)
            cout << "b:" << b->val;
        cout << endl;
        */

        ListNode *result = NULL;

        if (!a)
        {
            return b;
        }
        if (!b)
        {
            return a;
        }

        if (a->val <= b->val)
        {
            result = a;
            result->next = sortMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = sortMerge(a, b->next);
        }
        return result;
    }
};