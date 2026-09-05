#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head,
return an array of length 2 containing [minDistance, maxDistance]
where minDistance is the minimum distance between any two distinct critical points
and maxDistance is the maximum distance between any two distinct critical points.
If there are fewer than two critical points, return [-1, -1].
*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    friend class LL;
};

class LL
{
    ListNode *head;

public:
    LL()
    {
        head = nullptr;
    }
    void insert_at_begin(int num)
    {
        ListNode *p = new ListNode(num);

        if (head == 0)
        {
            head = p;
            return;
        }

        p->next = head;
        head = p;
    }

    void display()
    {
        ListNode *p = head;
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    ListNode *getHead()
    {
        return head;
    }
};

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    ListNode *p = head;
    vector<int> criticalPtsPos;

    int count = 2; // 1st node can never be a critical point

    while (p->next->next != nullptr)
    {
        ListNode *prev = p;
        ListNode *curr = prev->next;
        ListNode *next = curr->next;

        // local maxima
        if (curr->val > prev->val && curr->val > next->val)
        {
            criticalPtsPos.push_back(count);
        }

        // local minima
        if (curr->val < prev->val && curr->val < next->val)
        {
            criticalPtsPos.push_back(count);
        }

        count++;
        p = p->next;
    }

    int totalCriticalPts = criticalPtsPos.size();

    if (totalCriticalPts < 2)
        return {-1, -1};

    int minDistance = criticalPtsPos[1] - criticalPtsPos[0];
    int maxDistance = criticalPtsPos[totalCriticalPts - 1] - criticalPtsPos[0];

    for (int i = 1; i < totalCriticalPts - 1; i++)
    {
        minDistance = min(criticalPtsPos[i + 1] - criticalPtsPos[i], minDistance);
    }

    return {minDistance, maxDistance};
}

int main()
{
    LL list;

    list.insert_at_begin(7);
    list.insert_at_begin(2); 
    list.insert_at_begin(2); 
    list.insert_at_begin(2);
    list.insert_at_begin(3); 
    list.insert_at_begin(2);
    list.insert_at_begin(2); 
    list.insert_at_begin(3); 
    list.insert_at_begin(1); 
    // list.insert_at_begin(2); 
    // list.insert_at_begin(4);
    // list.insert_at_begin(6); 
    // list.insert_at_begin(2);

    list.display();

    ListNode *head = list.getHead();
    auto result = nodesBetweenCriticalPoints(head);

    for (int x : result)
    {
        cout << x << " ";
    }
}

/*

*/