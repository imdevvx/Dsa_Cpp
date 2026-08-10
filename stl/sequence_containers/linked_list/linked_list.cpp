#include <iostream>
using namespace std;

class LLnode
{
private:
    int data;
    LLnode *next; // pointer to another LLnode
public:
    LLnode(int num = 0, LLnode *ptr = 0)
    {
        data = num;
        next = ptr;
    }

    friend class LL; // Granting entire Class LL access to Class LLnodes's private members
};

class LL
{
private:
    LLnode *head; // head is not a node itself, but a ptr that sores the address of the first node (LLnode).

public:
    LL()
    {
        head = 0; // nullPtr
    }

    void insert_at_begin(int num)
    {
        LLnode *p = new LLnode(num); // p is a ptr to LLnode
        // new LLnode(num) returns a memory address which gets stored in p.

        // check empty linked list
        if (head == 0)
        {
            head = p; // make head point to the new node
            return;
        }
        else
        {
            p->next = head; // since p is a ptr we use p->next to access member of LLnode.
            head = p;       // make head point to the new node
        }

        /*
        Explanantion -:

        Step 1
        Assume initial state: head -> [10 | ] -> [20 | ] -> [30 | NULL]

        Step 2
        Create a new node: new_node = [5 | Null]

        Step 3
        Link the new_node to the current head => new_node->next = head

        newNode
           |
           v
        [5 | 100] -----> [10 | 200] -> [20 | 300] -> [30 | NULL]
                             ^
                             |
                            head
        Notice we haven't changed head yet.

        Step 4
        Update address of head => head = new_node

        head
          |
          v
      [5 | 100] -> [10 | 200] -> [20 | 300] -> [30 | NULL]
                      ^
                      |
                   old head
        */
    }

    void insert_at_end(int num)
    {
        LLnode *p = new LLnode(num);

        // check empty linked list
        if (head == 0)
        {
            head = p; // make head point to the first node
            return;
        }

        LLnode *q = head; // q is a ptr pointing to head (first node of LLnode)

        while (q->next != 0)
        {
            q = q->next; // move q forward till q reaches last node
        }

        q->next = p; // change the last node address (next) to new_node (p)
    }

    void insert_at_pos(int num, int position)
    {
        if (position == 1)
        {
            insert_at_begin(num);
            return;
        }

        LLnode *q = head;

        for (int i = 1; i < position - 1; i++)
        {
            if (q == 0)
            {
                cout << "Position out of bounds" << endl;
                return;
            }
            q = q->next;
        }

        if (q == 0)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        LLnode *p = new LLnode(num);

        p->next = q->next; // connect new node to the next node
        q->next = p;       // connect previous node to new node
    }

    void search(int element)
    {
        LLnode *p = head;
        while (p != 0 && p->data != element)
        {
            p = p->next;
        }
        if (p == 0)
        {
            cout << "Node not found" << endl;
            return;
        }
        else
        {
            cout << "Element found at address: " << p;
        }
    }

    void delete_at_end()
    {
        LLnode *p = head;

        // Empty list
        if (head == 0)
        {
            cout << "List is empty" << endl;
            return;
        }

        // Only one node
        if (p->next == 0)
        {
            delete p;
            head = 0;
            return;
        }

        LLnode *q = p; // q will be the node just before p
        while (p->next != 0)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }

    void display()
    {
        LLnode *p = head;

        while (p != 0) // we didn't used p->next != 0 because then the last node wouldn't be printed
        {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "Null" << endl;
    }
};

int main()
{
    LL list;

    cout << "Initial list:" << endl;
    list.display();

    cout << "\nInserting 10 at beginning:" << endl;
    list.insert_at_begin(10);
    list.display();

    cout << "\nInserting 20 at beginning:" << endl;
    list.insert_at_begin(20);
    list.display();

    cout << "\nInserting 30 at end:" << endl;
    list.insert_at_end(30);
    list.display();

    cout << "\nInserting 15 at position 2:" << endl;
    list.insert_at_pos(15, 2);
    list.display();

    cout << "\nInserting 40 at position 5:" << endl;
    list.insert_at_pos(40, 5);
    list.display();

    cout << "\nSearching for 15:" << endl;
    list.search(15);

    cout << "\n\nSearching for 100:" << endl;
    list.search(100);

    cout << "\nDeleting from end:" << endl;
    list.delete_at_end();
    list.display();

    return 0;
}