#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void print2LL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *convertArrayto2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
};

// Deletion of Node -->>
Node *deleteHead(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *prev = head;
    head = head->next;

    if (head != nullptr)
    {
        head->back = nullptr;
    }

    prev->next = nullptr;
    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    Node *lastNode = temp->next;
    lastNode->back = nullptr;
    temp->next = nullptr;
    delete lastNode;
    return head;
}

Node *deleteKthNodeIN2LL(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    int cnt = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *front = temp->next;

    if (prev == nullptr && front == nullptr)
    {
        return nullptr;
    }
    else if (prev == nullptr)
    {
        return deleteHead(head);
    }
    else if (front == nullptr)
    {
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;

    return head;
}

int main()
{
    int k;
    vector<int> arr = {12, 13, 14, 15, 20, 24};
    Node *head = convertArrayto2LL(arr);

    cout << "Original doubly linked list-->>" << endl;
    print2LL(head);

    cout << endl
         << "Enter the value of k :";
    cin >> k;
    cout << endl
         << "After deletion of tail-->>" << endl;
    head = deleteKthNodeIN2LL(head, k);
    print2LL(head);
    return 0;
}