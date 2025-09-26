#include <bits/stdc++.h>
using namespace std;

// defining the Node -->>
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

// Conversion of Array into linked list-->>
Node *ConvertArraytoLL(vector<int> arr)
{
    Node *head = new Node(arr[0], nullptr);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Insertion at the front -->>
Node *insertAtFront(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}

// Insertion at the last of LL-->>
Node *insertAtlast(Node *head, int val)
{
    if (head == nullptr)
    {
        return new Node(val, nullptr);
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val, nullptr);
    temp->next = newNode;
    return head;
}

// Insertion at Kth place in Linked list-->>
Node *insertAtKthPlace(Node *head, int ele, int k)
{

    if (head == nullptr)
        return head;
        
    if (k == 1)
    {
        Node *temp = new Node(val, head);
        return temp;
    }
}

int main()
{
    vector<int> arr = {12, 13, 14, 15};
    Node *head = ConvertArraytoLL(arr);
    // head = insertAtFront(head, 100);
    head = insertAtlast(head, 100);

    // printing the linked list-->>
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
};