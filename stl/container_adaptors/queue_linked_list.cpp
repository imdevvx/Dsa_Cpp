#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};


template <class T>
class MyQueue
{
private:
    Node<T>* front;
    Node<T>* rear;
    int count;

public:

    // Constructor
    MyQueue()
    {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    // Destructor
    ~MyQueue()
    {
        while (!isEmpty())
        {
            remove();
        }
    }

    // Insert / Enqueue
    void insert(T value)
    {
        Node<T>* newNode = new Node<T>(value);

        // If queue is empty
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
    }

    // Delete / Dequeue
    T remove()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return T();
        }

        Node<T>* temp = front;

        T value = front->data;

        front = front->next;
        
        count--;
        
        // If queue became empty
        if (count == 0)
        {
            rear = nullptr;
        }
        
        delete temp;
        return value;
    }

    // Return front element
    T getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return T();
        }

        return front->data;
    }

    // Return rear element
    T getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return T();
        }

        return rear->data;
    }

    // Return size
    int size()
    {
        return count;
    }

    // Check empty
    bool isEmpty()
    {
        return front == nullptr;
    }
};


int main()
{
    MyQueue<int> q;

    q.insert(10);
    q.insert(20);
    q.insert(30);

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    cout << "Size: " << q.size() << endl;

    cout << "\nRemoved: " << q.remove() << endl;

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    
    return 0;
}