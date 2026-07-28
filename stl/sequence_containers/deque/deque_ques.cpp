#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(const deque<int> &dq);

int main()
{
    deque<int> dq;

    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);

    dq.push_front(0);
    dq.push_front(1);
    dq.push_front(2);

    cout << "---PUSH BACK AND PUSH FRONT---\n";
    printDeque(dq);
    cout << endl;

    cout << "\n---FIRST AND LAST ELEMENT---\n";
    cout << dq.front() << endl;
    cout << dq.back() << endl;

    cout << "\n---FIRST AND LAST ELEMENT REMOVED---\n";
    dq.pop_front();
    dq.pop_back();

    printDeque(dq);
    cout << endl;

    // Reverse the deque
    auto it = dq.begin();

    // print reversed deque using loop
    cout << "\n---REVERSE DQ PRINT USING LOOP---\n";
    for (int i = dq.size() - 1; i >= 0; i--)
    {
        cout << dq[i] << " ";
    }
    cout << endl;

    // reverse the original dq and print
    cout << "\n---REVERSE DQ USING ALGORITHM AND PRINT---\n";
    reverse(dq.begin(), dq.end());
    printDeque(dq);
    cout << endl;

    // sort
    cout << "\n---SORTED DQ---\n";
    sort(dq.begin(), dq.end());
    printDeque(dq);
    cout << endl;

    // even and odd
    cout << "\n---EVEN AND ODD COUNT---\n";
    int even = 0, odd = 0;
    for (int i = 0; i < dq.size(); i++)
    {
        if (dq[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    cout << "even: " << even << endl;
    cout << "odd: " << odd << endl;

    return 0;
}

void printDeque(const deque<int> &dq)
{
    for (auto elem : dq)
    {
        cout << elem << " ";
    }
}