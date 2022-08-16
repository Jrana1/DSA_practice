#include <bits/stdc++.h>
using namespace std;
// node struct
struct Node
{
    int data;
    Node *next;
};
/// function to create a new node
Node *create_node(int val)
{
    Node *ptr = new Node;
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

// function to add a new node at tail of a list
Node *add_node(Node *head, int val)
{
    Node *ptr = create_node(val);
    if (head == NULL)
    {
        head = ptr;
        return head;
    }
    while (head->next)
    {
        head = head->next;
    }
    head->next = ptr;
    return head;
}

// function to display all the element of a list
void display(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
/// function to find the length of a list
int len(Node *head)
{
    int cnt = 0;
    while (head)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

// function to add a new node at a given position
Node *insert(Node *head, int val, int pos)
{
    int len1 = len(head);
    if (pos < 0 || pos > len1)
    {
        return NULL;
    }
    Node *ptr = create_node(val);
    if (pos == 0)
    {
        ptr->next = head;
        head = ptr;
        return head;
    }
    for (int i = 1; i < pos; i++)
    {
        head = head->next;
    }
    ptr->next = head->next;
    head->next = ptr;
}
// function to delete all the appearance of a given element from a list

Node *delete_val(Node *head, int val)
{
    while (head && head->data == val)
    {
        Node *p = head;
        head = head->next;
        delete p;
    }
    if (head == NULL)
    {

        return head;
    }
    Node *prev = head;
    Node *nxt = head->next;

    while (nxt)
    {

        if (nxt->data == val)
        {
            Node *p = nxt;
            prev->next = nxt->next;
            nxt = nxt->next;
            delete p;
        }
        else
        {
            prev = nxt;
            nxt = nxt->next;
        }
    }
    return head;
}
// check if a list is sorted or not
bool isSorted(Node *head)
{

    Node *nxt = head->next;
    while (nxt)
    {

        if (nxt->data < head->data)
        {
            return false;
        }
        head = nxt;
        nxt = nxt->next;
    }
    return true;
}

/// print all the elements of a link list in reverse order using Recursion.

void print_reverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }                          // base case when list is empty return
    print_reverse(head->next); // recursive call for the next node
    cout << head->data << " "; // while returning back print the element
}
/// finding sum of all the elements of a linked list using Recursion
int find_sum(Node *head)
{

    if (head->next == NULL)
    {
        return head->data;
    }
    return head->data + find_sum(head->next);
}

// delete duplicates element from a sorted linked list
// also a leedCode problem : https://leetcode.com/problems/remove-duplicates-from-sorted-list
Node *delete_duplicates(Node *head)
{
    // Node *ptr = head;
    if (head == NULL)
    {
        return head;
    }
    Node *nxt = head->next;
    while (nxt)
    {

        if (nxt->data != head->data)
        {
            head = nxt;
            nxt = nxt->next;
        }
        else
        {
            head->next = nxt->next;
            delete nxt;
            nxt = head->next;
        }
    }
    // return ptr;
}

// Reversing a linked list using Sliding pointer (Three Pointer)

Node *reverse_iterative(Node *head)
{
    Node *p = head, *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

// Reversing using Recursion and two pointers
// in this case we have to declare head as Global
// Node *reverse1(Node *p, Node *q)
// {
//     if (p)
//     {

//         reverse1(p->next, p);
//         p->next = q;
//     }
//     else
//     {
//         head = q;
//     }
// }
// Another way of Reversing in a recursive way but using only one pointer

Node *reverse2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverse2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void concat_two_linked_list(Node *head1, Node *head2)
{
    while (head1->next)
    {
        head1 = head1->next;
    }
    head1->next = head2;
}

Node *merge_two_sorted_linked_list(Node *h1, Node *h2)
{

    Node *t = NULL, *l = NULL; // t=third head,l = last/tail

    if (h1->data < h2->data)
    {
        t = h1;
        l = h1;
        h1 = h1->next;
        l->next = NULL;
    }
    else
    {
        t = h2;
        l = h2;
        h2 = h2->next;
        l->next = NULL;
    }
    while (h1 && h2)
    {

        if (h1->data < h2->data)
        {
            l->next = h1;
            l = h1;
            h1 = h1->next;
            l->next = NULL;
        }
        else
        {
            l->next = h2;
            l = h2;
            h2 = h2->next;
            l->next = NULL;
        }
    }
    // while (h1)
    // {
    //     l->next = h1;
    //     l = h1;
    //     h1 = h1->next;
    //     l->next = NULL;
    // }
    // while (h2)
    // {
    //     l->next = h2;
    //     l = h2;
    //     h2 = h2->next;
    //     l->next = NULL;
    // }
    // or
    if (h1)
    {
        l->next = h1;
    }
    else
    {
        l->next = h2;
    }
    return t;
}
// detect if a Linked list has a loop or not using slow and fast pointer
bool hasLoop(Node *head)
{

    Node *slow = head, *fast = head;
    while (fast)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
/// another way to detect loop in a linked list is by using extra Space
bool hasLoop1(Node *head)
{

    multiset<Node *> nodes;
    while (head)
    {
        if (nodes.count(head) > 0)
        {
            return true;
        }
        else
        {
            nodes.insert(head);
        }
        head = head->next;
    }
    nodes.clear();
    return false;
}
int main()
{
    Node *head1 = NULL;

    head1 = add_node(head1, 1);
    add_node(head1, 2);
    add_node(head1, 0);
    add_node(head1, 3);
    cout << hasLoop1(head1) << endl;
    head1->next->next->next = head1->next;
    cout << hasLoop1(head1) << endl;

    return 0;
}