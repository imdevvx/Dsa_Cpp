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

    void find_middle()
    {
        if (head == 0)
        {
            cout << "List is empty" << endl;
            return;
        }

        LLnode *slow = head;
        LLnode *fast = head;

        while (fast != 0 && fast->next != 0)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle element: " << slow->data << endl;
    }

    void nth_from_end(int n)
    {
        LLnode *slow = head;
        LLnode *fast = head;

        for (int i = 0; i < n; i++)
        {
            if (fast == 0)
            {
                cout << "n is greater than list length" << endl;
                return;
            }
            fast = fast->next;
        }

        while (fast != 0)
        {
            slow = slow->next;
            fast = fast->next;
        }

        cout << n << "th node from end: " << slow->data << endl;
    }
};

int main()
{
    return 0;
}