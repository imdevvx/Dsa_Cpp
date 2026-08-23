#include <iostream>
using namespace std;

// create a new list after merge

class LLnode
{
private:
    int data;
    LLnode *next;

public:
    LLnode(int num = 0, LLnode *ptr = nullptr)
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
    LL() { head = nullptr; }

    LLnode *getHead() const { return head; }

    // Insert at begin
    void insert_at_beg(int num)
    {
        LLnode *p = new LLnode(num);
        p->next = head;
        head = p;
    }

    // Insert in sorted order
    void insert(int elem)
    {
        LLnode *p = new LLnode(elem);
        if (head == nullptr)
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
        while (q->next != nullptr && q->next->data < elem)
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }

    // FAST O(N) MERGE FUNCTION
    LL merge(const LL &list1, const LL &list2)
    {
        LL merged;
        LLnode *p = list1.head;
        LLnode *q = list2.head;

        LLnode *tail = nullptr; // Tracks the end of the new list

        while (p != nullptr && q != nullptr)
        {
            LLnode *newNode;
            if (p->data <= q->data)
            {
                newNode = new LLnode(p->data);
                p = p->next;
            }
            else
            {
                newNode = new LLnode(q->data);
                q = q->next;
            }

            // Append newNode directly to the tail
            if (merged.head == nullptr)
            {
                merged.head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }

        // Append remaining elements of list1
        while (p != nullptr)
        {
            LLnode *newNode = new LLnode(p->data);
            if (merged.head == nullptr)
            {
                merged.head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            p = p->next;
        }

        // Append remaining elements of list2
        while (q != nullptr)
        {
            LLnode *newNode = new LLnode(q->data);
            if (merged.head == nullptr)
            {
                merged.head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            q = q->next;
        }

        return merged;
    }

    // Display
    void display(LLnode *ptr) const
    {
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    LL list1, list2, creator;

    // Create List 1: 1 -> 3 -> 5
    list1.insert(3);
    list1.insert(1);
    list1.insert(5);
    cout << "List 1: ";
    list1.display(list1.getHead());

    // Create List 2: 2 -> 4 -> 6
    list2.insert(4);
    list2.insert(2);
    list2.insert(6);
    cout << "List 2: ";
    list2.display(list2.getHead());

    // Merge them
    LL mergedList = creator.merge(list1, list2);
    cout << "Merged List: ";
    mergedList.display(mergedList.getHead());

    return 0;
}
