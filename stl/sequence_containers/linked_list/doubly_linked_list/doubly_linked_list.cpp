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

    friend class Dll;
};

class Dll
{
    DLLnode *head;
    int list_size;

public:
    Dll()
    {
        head = 0;
        list_size = 0;
    }

    void insert_at_beg(int n)
    {
        DLLnode *p = new DLLnode(n);

        // empty list
        if (head == 0)
        {
            head = p;
            list_size++;
            return;
        }

        p->next = head;
        head->prev = p;
        head = p;

        list_size++;
    }

    void insert_at_end(int n)
    {
        DLLnode *p = new DLLnode(n);
        DLLnode *q = head;

        // empty list
        if (head == 0)
        {
            head = p;
            list_size++;
            return;
        }

        while (q->next != 0)
        {
            q = q->next;
        }

        q->next = p;
        p->prev = q;

        list_size++;
    }

    void insert_at_pos(int n, int pos)
    {
        DLLnode *p = new DLLnode(n);
        DLLnode *q = head;
        
        // empty list
        if (head == 0)
        {
            head = p;
            list_size++;
            return;
        }
        
        for (int i = 1; i < pos - 1; i++)
        {
            if (q == 0)
            {
                cout << "Position out of bounds" << endl;
                return;
            }
            q = q->next; // the node just before the position
        }
        
        if (q == 0)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        p->next = q->next;
        q->next = p;
        p->prev = q;

        list_size++;
        
        }
};

int main()
{
    return 0;
}