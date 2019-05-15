// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head;
        ListNode *pre = head;
        ListNode *post = head;
        int len = 0;
        for (len = 0; p; len++)
            p = p->next;
        int pos = len - n;
        if (pos == 0)
            return head->next;
        p = head;
        for (int i = 0; i < pos; i++)
        {
            pre = p;
            p = p->next;
            post = p->next;
        }
        pre->next = post;
        return head;
    }
};

void show(ListNode *p)
{
    for (; p; p = p->next)
        cout << p->val << " ";
}

int main(int argc, char *argv[])
{
    int pos = std::stoi(argv[1]);
    ListNode l(-1);
    ListNode *p = &l;
    // int pos[] = {0, 1, 2, 3, 4, 5};
    for (int i = 0; i < 6; i++)
    {
        p->next = new ListNode(i);
        p = p->next;
    }
    show(&l);
    cout << " | " << pos << " | ";
    ListNode *q = Solution().removeNthFromEnd(&l, pos);
    show(q);
    cout << endl;
}