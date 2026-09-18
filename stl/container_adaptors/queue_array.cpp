#include <iostream>
using namespace std;

template <class T>
class MyQueue
{
private:
    T *arr;       // array of T data type to store elements
    int capacity; // max number of elements
    int count;    // curr number of elements
    int frontIdx; // index of front element
    int rear;     // index where the next element will be inserted
public:
    MyQueue(int cap = 10)
    {
        capacity = cap;
        arr = new T[capacity];

        count = 0;
        frontIdx = 0;
        rear = 0;
    }

    int getCapacity() { return capacity; }

    int getSize() { return count; }

    bool isEmpty() { return count == 0; }

    bool isFull() { return count == capacity; }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T(); // If T is an int, int() returns 0
        }
        return arr[frontIdx];
    }

    T back()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }

        // rearIndex points to the NEXT insertion position,
        // so actual rear is one position behind it.
        int index = (rear - 1 + capacity) % capacity;
        return arr[index];
    }

    void insert(T elem)
    {
        if (isFull())
        {
            cout << "Queue is full.." << endl;
            return;
        }
        arr[rear] = elem;
        rear = (rear + 1) % capacity;
        count++;
    }

    T remove()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.." << endl;
            return T();
        }

        T value = arr[frontIdx];

        frontIdx = (frontIdx + 1) % capacity;
        count--;

        return value;
    }

    ~MyQueue()
    {
        delete[] arr;
    }
};

int main()
{

    MyQueue<int> q(5);

    q.insert(10);
    q.insert(20);
    q.insert(30);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.getSize() << endl;
    cout << "Capacity: " << q.getCapacity() << endl;

    cout << "\nRemoving: " << q.remove() << endl;

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    
    return 0;
}