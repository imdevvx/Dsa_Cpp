/*
Given the head of a sorted linked list, 
delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p = head;

        while (p != nullptr && p->next != nullptr)
        {
            if (p->val == p->next->val)
            {
                ListNode *q = p->next;
                p->next = q->next;
                delete q;
            }
            else
            {
                p = p->next;
            }
        }

        return head;
    }
};
