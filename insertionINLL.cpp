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

// Linked List print function-->>
void printLL(Node *head)
{

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

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
    {
        if (k == 1)
        {
            return new Node(ele, nullptr);
        }
        else
            return nullptr;
    }
    if (k == 1)
    {
        Node *temp = new Node(ele, head);
        return temp;
    }

    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k - 1)
        {
            Node *newNode = new Node(ele, nullptr);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

// Insertion before particular node-->>
Node *insertBeforeGivenNode(Node *head, int ele, int val)
{

    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->data == val)
    {
        Node *newNode = new Node(ele, nullptr);
        return newNode;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        if (temp->next->data == val)
        {
            Node *newNode = new Node(ele, nullptr);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
};

int main()
{

    int k;
    int val;
    vector<int> arr = {12, 13, 14, 15};
    Node *head = ConvertArraytoLL(arr);
    // head = insertAtFront(head, 100);
    // head = insertAtlast(head, 100);

    // for Kth Node Function-->>
    // cout << "Enter k" << endl;
    // cin >> k;

    // head = insertAtKthPlace(head, 19, k);

    // for BeforeGivenNode Function-->>
    cout << "Enter val" << endl;
    cin >> val;

    head = insertBeforeGivenNode(head, 20, val);

    printLL(head);
};