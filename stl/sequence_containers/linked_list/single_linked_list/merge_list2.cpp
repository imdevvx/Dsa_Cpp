#include <iostream>
using namespace std;

// merge two sorted list best approach

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

    LLnode *getHead()
    {
        return head;
    }

    // Insert at begin
    void insert_at_beg(int num)
    {
        LLnode *p = new LLnode(num);

        p->next = head;
        head = p;
    }

    // Insert
    void insert(int elem)
    {
        LLnode *p = new LLnode(elem);

        // If list is empty
        if (head == 0)
        {
            head = p;
            return;
        }

        if (elem < head->data)
        {
            insert_at_beg(elem);
            return;
        }

        LLnode *q = head;
        while (q->next != 0 && q->next->data < elem)
        {
            q = q->next;
        }

        p->next = q->next;
        q->next = p;
    }

    // Merge
    LLnode *merge(LLnode *head1, LLnode *head2)
    {
        LLnode *merged_head = 0; // ptr where the merged list starts
        LLnode *p = 0;           // ptr where we are currently adding the next node

        if (head1 == 0 || head2 == 0)
        {
            return head1 == 0 ? head2 : head1;
        }

        while (head1 != 0 && head2 != 0)
        {
            if (head1->data <= head2->data)
            {
                if (merged_head == 0)
                {
                    merged_head = head1;
                    p = merged_head;
                }
                else
                {
                    p->next = head1;
                    p = p->next;
                }
                head1 = head1->next;
            }

            else if (head2->data < head1->data)
            {
                if (merged_head == 0)
                {
                    merged_head = head2;
                    p = merged_head;
                }
                else
                {
                    p->next = head2;
                    p = p->next;
                }

                head2 = head2->next;
            }
        }

        if (head1 != 0)
        {
            p->next = head1;
        }
        else
        {
            p->next = head2;
        }

        return merged_head;
    }

    // Display
    void display(LLnode *ptr)
    {
        while (ptr != 0)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }

        cout << endl;
    }
};

int main()
{
    LL list1;
    LL list2;

    list1.insert(1);
    list1.insert(5);
    list1.insert(2);

    list2.insert(3);
    list2.insert(7);
    list2.insert(4);
    list2.insert(6);

    LLnode* head1 = list1.getHead();
    LLnode* head2 = list2.getHead();

    LLnode* merged = list1.merge(head1, head2);
    list1.display(merged);

    return 0;
}