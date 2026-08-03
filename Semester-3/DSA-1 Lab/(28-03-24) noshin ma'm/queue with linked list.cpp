#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    if (rear == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

}

int dequeue()
{
    if (front == nullptr)
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;
    }
    int dequeuedValue = front->data;
    Node* temp = front;
    if (front == rear)
    {
        front = rear = nullptr;
    }
    else
    {
        front = front->next;
    }
    delete temp;
    return dequeuedValue;
}

int frontValue()
{
    if (front == nullptr)
    {
        cout << "Queue is empty." <<
             endl;
        return -1;
    }
    return front->data;
}

int rearValue()
{
    if (rear == nullptr)
    {
        cout << "Queue is empty." <<endl;
        return -1;
    }
    return rear->data;
}

bool isEmpty()
{
    return (front == nullptr);
}

int size()
{
    int count = 0;
    Node* current = front;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void display()               ///Print
{
    if (front == nullptr)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue (front to back): ";
    Node* current = front;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int choice, value;

    while (true)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Empty\n6. Size\n7. Display\n8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
        {
            int dequeuedValue = dequeue();
            if (dequeuedValue != -1)
                cout << "Dequeued value: " << dequeuedValue << endl;
            break;
        }
        case 3:
            cout << "Front value: " << frontValue() << endl;
            break;
        case 4:
            cout << "Rear value: " << rearValue() << endl;
            break;
        case 5:
            cout << (isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
            break;
        case 6:
            cout << "Size of the queue: " << size() << endl;
            break;
        case 7:
            display();
            break;
        case 8:
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
