#include <iostream>
using namespace std;

/*
Doubly linked list: each node knows both the previous and the next node => [prev | data | next]

head
 |
 v
[NULL | 10 | *] <----> [* | 20 | *] <----> [* | 30 | NULL]
*/

class DLLnode
{
    int data;
    DLLnode *prev;
    DLLnode *next;

public:
    DLLnode(int n = 0, DLLnode *pv = 0, DLLnode *nxt = 0)
    {
        data = n;
        prev = pv;
        next = nxt;
    }

    friend Dll;
};

class Dll
{
    DLLnode *head; // ptr to first node
    DLLnode *tail; // ptr to last node

public:
    Dll()
    {
        head = 0;
        tail = 0;
    }

    void insert_at_beg(int n)
    {
        DLLnode *p = new DLLnode(n);

        if (head == 0)
        {
            head = p;
            tail = p;
            return;
        }

        p->next = head;
        head->prev = p;
        head = p;
    }

    void insert_at_end(int n)
    {
        DLLnode *p = new DLLnode(n);

        if (head == 0)
        {
            head = p;
            tail = p;
            return;
        }

        tail->next = p;
        p->prev = tail;
        tail = p;
    }

    void insert_at_pos(int n, int pos)
    {
        if (pos == 1)
        {
            insert_at_beg(n);
            return;
        }
        
        DLLnode *p = new DLLnode(n);
        DLLnode *q = head;

        if (head == 0)
        {
            head = p;
            tail = p;
            return;
        }

        for (int i = 1; i < pos - 1; i++)
        {
            if (q == 0)
            {
                cout << "Position out of bounds" << endl;
                delete p;
                return;
            }
            q = q->next; // the node just before the position
        }

        if (q == 0)
        {
            cout << "Position out of bounds" << endl;
            delete p;
            return;
        }

        p->next = q->next;
        q->next = p;
        p->prev = q;

        if (p->next != 0)
        {
            p->next->prev = p;
        }
        else
        {
            tail = p;
        }
    }
    void reverse()
    {
        DLLnode *p = head;
        head = tail;
        tail = p;

        while (p != 0){
            DLLnode* temp;

            // swap prev and next
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;

            // move forward
            p = p->prev;
        }
    }
};

int main()
{
    return 0;
}