#include <bits/stdc++.h>
using namespace std;

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
    };
};

// convertion of Array into Linked list-->>

Node *convertarrtoLinkedlist(vector<int> arr)
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
};

// finding Length of linked list-->>

int LengthOFLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " " << endl;
        temp = temp->next;
        cnt++;
    }
    return cnt;
};

// deleting the head of linked list-->>

Node *deleteHeadOFLL(Node *head)
{

    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// deleting the tail of linked list-->>

Node *deleteTailOFLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// Remove kth node from the linked list-->>

Node *removeKthNode(Node *head, int k)
{

    if (head == nullptr)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        temp = temp->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


// remove particular ele from the sigli linked list-->>

Node *removeEle(Node *head, int el)
{
    if (head == nullptr)
        return head;

    if (head->data == el)
    {
        Node *temp = head;
        temp = temp->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->data == el)
        {
            prev->next == prev->next->next;
            delete temp;
            break;
        }
    }

    return head;
}

int main()
{
    int k;
    vector<int> arr = {13, 14, 15, 16};
    Node *head = convertarrtoLinkedlist(arr);
    cout << "Length of LL:" << LengthOFLL(head) << " " << endl;
    // head = deleteHeadOFLL(head);
    // head = deleteTailOFLL(head);
    // cout << "Give k" << " " << endl;
    cin >> k;
    // head = removeKthNode(head, k);
    head = removeEle(head, 14);
    // cout << head->next->next->data << " " << endl;
    cout << LengthOFLL(head) << " " << endl;
    cout << head->next->data << " " << endl;
};