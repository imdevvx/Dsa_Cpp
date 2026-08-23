#include <iostream>
using namespace std;

// merge two sorted list using recursion

class LLnode
{
private:
    int data;
    LLnode *next;

public:
    LLnode(int num = 0, LLnode *ptr = 0)
    {
        data = num;
        next = ptr;
    }

    friend class LL;
};

class LL
{
private:
    LLnode *head;

public:
    LL()
    {
        head = 0;
    }

    LLnode *merge(LLnode *head1, LLnode *head2)
    {
        // if list is empty
        if (head1 == 0 || head2 == 0)
        {
            return head1 == 0 ? head2 : head1;
        }

        // case 1
        if (head1->data <= head2->data)
        {
            head1->next = merge(head1->next, head2);
            return head1;
        }

        // case 2
        else
        {
            head2->next = merge(head1, head2->next);
            return head2;
        }
    }
};

int main()
{
    return 0;
}