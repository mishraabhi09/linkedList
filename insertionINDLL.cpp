#include <bits/stdc++.h>
#include <iostream>
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
        data1 = data;
        next1 = next;
        back1 = back;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
};

Node *convertArrayToDLL(vector<int> arr)
{

    // If array is empty-->>
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

// insertion before head-->>
Node *insertbeforeHead(Node *head, int ele)
{
    if (head == NULL)
    {
        Node *newHead = new Node(ele);
        return newHead;
    }

    Node *temp = head;
    Node *newHead = new Node(ele);
    newHead->next = temp;
    temp->back = newHead;
    return newHead;
}

// insertion before tail-->>
Node *insertbeforeTail(Node *head, int ele)
{
    if (head == nullptr)
    {
        return insertbeforeHead(head, ele);
    }

    if (head->next == NULL)
    {
        return insertbeforeHead(head, ele);
    }

    Node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(ele);
    newNode->back = temp;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// insertion before kth Node-->>
Node *insertbeforeKthNode(Node *head, int ele, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {

            // Node *newNode = new Node(ele);
            // return newNode;

            return insertbeforeHead(head, ele);
        }
    }

    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            Node *newNode = new Node(ele);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }
    return head;
}



int main()
{
    vector<int> arr = {12, 13, 14, 15, 17};
    // vector<int> arr = {12};
    // vector<int> arr = {};

    int givenval;
    Node *head = convertArrayToDLL(arr);

    // before insertion-->>
    cout << "Original DLL-->>" << endl;
    printDLL(head);

    // after insertion-->>
    cout << endl
         << "After insertion before tail-->>" << endl;
    head = insertbeforeKthNode(head , 100 , 2);
    printDLL(head);

    return 0;
}