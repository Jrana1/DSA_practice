#include <bits/stdc++.h>
using namespace std;
// struct Node
struct Node
{
    int data;
    Node *prev, *next;
};
// create a new node
Node *create_node(int val)
{

    Node *ptr = new Node;
    ptr->data = val;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

// add a new node at the end of the list
Node *add_node(int val, Node *head)
{

    Node *ptr = create_node(val);
    // case 1: if the list is empty
    if (head == NULL)
    {
        head = ptr;
        return head;
    }
    // case 2: if the list has at least one element
    while (head->next)
    {
        head = head->next;
    }
    head->next = ptr;
    ptr->prev = head;
}

// display all the element of a linked list
void display(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// display all the element of a linked list but in reverse order using prev pointer
void display_reverse(Node *ptr)
{ // first go to the tail of the list
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    // now go from back to front using prev pointer
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
    cout << endl;
}
// add a new Node at the head of a  list
Node *add_at_head(int val, Node *head)
{

    Node *ptr = create_node(val);
    if (head == NULL)
    {
        head = ptr;
        return head;
    }
    head->prev = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// function to add a new node at a given position
Node *insert_at_pos(Node *head, int pos, int val)
{
    // Case 1: if the given position is zero then we have to handle it specially
    if (pos == 0)
    {
        return add_at_head(val, head);
    }
    // bring the head pointer before the node where to add a new node
    Node *ptr = create_node(val);
    for (int i = 0; i < pos - 1; i++)
    {
        head = head->next;
    }
    ptr->next = head->next;
    ptr->prev = head;
    if (head->next)
    {
        head->next->prev = ptr;
    }
    head->next = ptr;
    // cout << head->data << endl;
}
/// delete all the element of a list which are equal to val
Node *delete_val(Node *head, int val)
{
    // Case 1: if the element is at head

    while (head->data == val && head)
    {
        Node *ptr = head;
        head = head->next;
        if (head->next)
        {
            head->prev = NULL;
        }
    }
    if (head == NULL) // return NULL if the list has become till here empty
        return head;
    // Case 2: if the to be deleted element located at middle of  the list or at end of list
    Node *ptr = head;
    while (head)
    {

        if (head->data == val)
        {

            head->prev->next = head->next;
            if (head->next)
            {
                head->next->prev = head->prev;
            }
        }
        head = head->next;
    }

    return ptr;
}

// find middle of a linked list
// Method 1: find the len of the linked ist then traverse the list len/2 times
// find the len of a list
int find_len(Node *head)
{
    int cnt = 0;

    for (; head != NULL; head = head->next)
    {
        cnt++;
    }
    return cnt;
}

Node *find_mid_node(Node *head, int mid)
{
    for (int x = 1; x <= mid; x++)
    {
        head = head->next;
    }
    return head;
}
/// Method 2: using slow and fast Pointer

Node *find_mid_node1(Node *head)
{

    Node *slow = head, *fast = head;
    while (fast->next)
    {

        slow = slow->next;
        fast = fast->next;
        if (fast->next)
        {
            fast = fast->next;
        }
    }
    return slow;
}

/// Method 3: using Stack

Node *find_mid_node2(Node *head)
{

    stack<Node *> nodes;
    Node *ptr = head;
    while (ptr)
    {
        nodes.push(ptr);
        ptr = ptr->next;
    }
    int mid = nodes.size() / 2;
    while (mid--)
    {
        // cout << nodes.top()->data << endl;
        nodes.pop();
    }
    return nodes.top();
}

int main()
{

    // Node *first = NULL;
    // first = add_node(1, first);
    // add_node(2, first);
    // add_node(3, first);
    // add_node(4, first);
    // add_node(5, first);
    // // add_node(6, first);
    // // add_node(6, first);
    // //  add_node(9, first);
    // //  add_node(8, first);
    // //  add_node(6, first);
    // //  add_node(6, first);
    // //  first = add_at_head(8, first);
    // //  first = insert_at_pos(first, 0, 12);
    // //  insert_at_pos(first, 4, 13);
    // //  first = delete_val(first, 4);
    // display(first);
    // // find_mid_node2(first);

    // cout << find_mid_node2(first)->data << endl;

    return 0;
}