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

    friend class CircularLL;
};

class CircularLL
{
private:
    LLnode *head;
    int list_size;

public:
    CircularLL()
    {
        head = 0;
    }

    void insert_at_beg(int num)
    {
        LLnode *p = new LLnode(num);

        if (head == 0)
        {
            head = p;
            p->next = head;
            return;
        }

        LLnode *last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        p->next = head;
        head = p;
        last->next = head;
    }

    void insert_at_end(int num)
    {
        LLnode *p = new LLnode(num);

        if (head == 0)
        {
            head = p;
            p->next = head;
            return;
        }

        LLnode *last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        last->next = p;
        p->next = head;
    }

    bool has_cycle()
    {
        LLnode *slow = head;
        LLnode *fast = head;

        while (fast != 0 && fast->next != 0)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }

    void display()
    {
        if (head == 0)
        {
            cout << "List is empty" << endl;
            return;
        }

        LLnode *p = head;

        do
        {
            cout << p->data << " -> ";
            p = p->next;
        } while (p != head);
    }
};

int main()
{
    CircularLL list;

    list.insert_at_beg(30);
    list.insert_at_beg(10);
    list.insert_at_beg(40);
    list.insert_at_end(20);
    list.insert_at_end(25);
    list.insert_at_end(5);

    cout << "Ordered linked list: ";
    list.display();

    return 0;
}