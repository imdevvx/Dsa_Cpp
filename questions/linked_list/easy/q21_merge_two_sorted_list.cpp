/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. 
The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *merged_head = 0; // head of the merged linked list;
        ListNode *p = 0;           // tracks the node where we want to insert

        // list1 and list2 are head of lists
        if (list1 == nullptr || list2 == nullptr)
        {
            return list1 == nullptr ? list2 : list1;
        }

        while (list1 != 0 && list2 != 0)
        {

            if (list1->val <= list2->val)
            {
                if (merged_head == 0)
                {
                    merged_head = list1;
                    p = merged_head;
                }
                else
                {
                    p->next = list1;
                    p = p->next;
                }
                list1 = list1->next;
            }

            else
            {
                if (merged_head == 0)
                {
                    merged_head = list2;
                    p = merged_head;
                }
                else
                {
                    p->next = list2;
                    p = p->next;
                }
                list2 = list2->next;
            }
        }

        if (list1 != 0)
        {
            p->next = list1;
        }
        else
        {
            p->next = list2;
        }

        return merged_head;
    }
};