#include <iostream>
using namespace std;

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

    void insert_at_beg(int num)
    {
        LLnode *p = new LLnode(num);

        p->next = head;
        head = p;
    }

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

    void display()
    {
        LLnode *p = head;
        while (p != 0)
        {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }
};

int main()
{
    LL list;

    list.insert(30);
    list.insert(10);
    list.insert(40);
    list.insert(20);
    list.insert(25);
    list.insert(5);

    cout << "Ordered linked list: ";
    list.display();
    
    return 0;
}