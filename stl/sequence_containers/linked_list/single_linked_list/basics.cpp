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
    int list_size;

public:
    LL()
    {
        head = 0; // nullPtr
        list_size = 0;
    }

    void insert_at_begin(int num)
    {
        LLnode *p = new LLnode(num); // p is a ptr to LLnode
        // new LLnode(num) returns a memory address which gets stored in p.

        // check empty linked list
        if (head == 0)
        {
            head = p; // make head point to the new node
            list_size++;
            return;
        }

        p->next = head; // since p is a ptr we use p->next to access member of LLnode.
        head = p;       // make head point to the new node

        list_size++;

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
            list_size++;
            return;
        }

        LLnode *q = head; // q is a ptr pointing to head (first node of LLnode)

        while (q->next != 0)
        {
            q = q->next; // move q forward till q reaches last node
        }

        q->next = p; // change the last node address (next) to new_node (p)

        list_size++;
    }

    void insert_at_pos(int num, int position)
    {
        if (position <= 0)
        {
            cout << "Invalid position" << endl;
            return;
        }

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
            q = q->next; // the node just befor the position
        }

        if (q == 0)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        LLnode *p = new LLnode(num);

        p->next = q->next; // connect new node to the next node
        q->next = p;       // connect previous node to new node

        list_size++;
    }

    int search(int element)
    {
        LLnode *p = head;
        int position = 0;

        while (p != 0 && p->data != element)
        {
            p = p->next;
            position++;
        }

        if (p == 0)
        {
            return -1;
        }

        return position;
    }

    void delete_at_beg()
    {
        if (head == 0)
        {
            cout << "List is empty" << endl;
            return;
        }

        LLnode *p = head;
        head = p->next;
        delete p;

        list_size--;
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
            list_size--;
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

        list_size--;
    }

    void delete_at_pos(int position)
    {
        LLnode *q = head;
        LLnode *r = q; // Node just befor q

        if (head == 0)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (position == 0)
        {
            delete_at_beg();
            return;
        }

        for (int i = 0; i < position; i++)
        {
            r = q;
            q = q->next;

            if (q == 0)
            {
                cout << "Position out of bounds" << endl;
                return;
            }
        }

        r->next = q->next;
        delete q;

        list_size--;
    }

    int length()
    {
        return list_size;
        
        /*
        This function is O(N) (Linear Time). This can slow down the program if we call length() frequently.
        The optimal approach is O(1) (Constant time). Where we track the size automatically whenever we insert or delete a node.

        LLnode *p = head;
        int count = 0;
        while (p != 0)
        {
            p = p->next;
            count++;
        }
        return count;
        */
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
    int position = list.search(15);
    if (position != -1)
        cout << "Element found at position: " << position << endl;
    else
        cout << "Element not found" << endl;

    cout << "\n\nSearching for 100:" << endl;
    auto position2 = list.search(100);
    if (position2 != -1)
        cout << "Element found at position: " << position2 << endl;
    else
        cout << "Element not found" << endl;

    cout << "\nDeleting from end:" << endl;
    list.delete_at_end();
    list.display();

    return 0;
}

/*
| Operation           |     Time |
| ------------------- | -------: |
| Insert at beginning |   O(1)   |
| Insert at end       |   O(n)   |
| Insert at position  |   O(n)   |
| Search              |   O(n)   |
| Display             |   O(n)   |
| Delete beginning    |   O(1)   |
| Delete end          |   O(n)   |
| Delete position     |   O(n)   |
| Length              |O(n), O(1)|
| Find middle         |   O(n)   |
| Reverse             |   O(n)   |

*/