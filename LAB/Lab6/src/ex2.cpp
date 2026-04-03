#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initQueue(Queue& q)
{
    q.front = q.rear = NULL;
}

bool isEmpty(Queue q)
{
    return q.front == NULL;
}

void enqueue(Queue& q, int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = NULL;

    if (isEmpty(q))
    {
        q.front = q.rear = p;
    }
    else
    {
        q.rear->next = p;
        q.rear = p;
    }
}

int dequeue(Queue& q)
{
    if (isEmpty(q))
        return -1;

    Node* temp = q.front;
    int x = temp->data;

    q.front = q.front->next;
    if (q.front == NULL)
        q.rear = NULL;

    delete temp;
    return x;
}

int getFront(Queue q)
{
    return q.front->data;
}

int main()
{
    Queue q1, q2;
    initQueue(q1);
    initQueue(q2);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        enqueue(q1, x);
    }

    for (int i = 0; i < n; i++)
    {
        int size = n - i;
        int minVal = getFront(q1);

        for (int j = 0; j < size; j++)
        {
            int x = dequeue(q1);
            if (x < minVal)
                minVal = x;
            enqueue(q2, x);
        }

        bool removed = false;

        for (int j = 0; j < size; j++)
        {
            int x = dequeue(q2);
            if (x == minVal && !removed)
            {
                cout << x << " ";
                removed = true;
            }
            else
            {
                enqueue(q1, x);
            }
        }
    }

    return 0;
}
