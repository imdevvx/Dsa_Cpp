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

    // void reverse()
    // {
    //     LLnode *prev = 0;
    //     LLnode *curr = head;
    //     LLnode *next = 0;

    //     while (curr != 0)
    //     {
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }

    //     head = prev;
    // }

    void reverse()
    {
        LLnode *p = head;
        LLnode *q = p->next;
        LLnode *r;
        p->next = 0;

        while (q->next != 0)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }

        q->next = p;
        head = q;
    }
};

int main()
{
    return 0;
}
