#include <iostream>
#include <vector>
using namespace std;

/*
Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes
(i.e., only nodes themselves may be changed.)
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    friend class LL;
};

class LL
{
    ListNode *head;

public:
    LL()
    {
        head = nullptr;
    }
    void insert_at_begin(int num)
    {
        ListNode *p = new ListNode(num);

        if (head == 0)
        {
            head = p;
            return;
        }

        p->next = head;
        head = p;
    }

    void display()
    {
        ListNode *p = head;
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    ListNode *getHead()
    {
        return head;
    }
};

ListNode *swapPairs(ListNode *head)
{
    // if the list is empty or has only one node, no swaps
    if (!head || !head->next)
        return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    // Traverse the list as long as there is a pair to swap
    while (prev->next && prev->next->next)
    {
        ListNode *first = prev->next;
        ListNode *second = prev->next->next;

        // Point the previous node to the second node
        prev->next = second;
        
        // Point the first node to the rest of the list
        first->next = second->next;

        // Point the second node back to the first node (i.e swap)
        second->next = first;

        // Move the prev ptr two step forward to prepare for the next pair
        prev = first;
    }

    return dummy.next;
}

int main()
{
    LL list;

    list.insert_at_begin(4);
    list.insert_at_begin(3);
    list.insert_at_begin(2);
    list.insert_at_begin(1);

    list.display();

    ListNode *head = list.getHead();
    swapPairs(head);
}

/*
int nodes_count = 0;
    while (p != nullptr)
    {
        nodes_count++;
        p = p->next;
    }
    cout << nodes_count;
*/